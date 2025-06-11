#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include "metrics_storage.h"
#include "cpu_usage_metric.h"
#include "http_request_count_metric.h"
#include "memory_usage_metric.h"
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    try {
        if (fs::exists("metrics.txt")) {
            fs::remove("metrics.txt");
        }

        MetricsStorage storage("metrics.txt");

        CpuUsageMetric cpu_metric("CPU");
        HttpRequestCountMetric http_metric("HTTP requests RPS");
        MemoryUsageMetric mem_metric("Memory Usage");

        for (int i = 0; i < 10; ++i) {
            cpu_metric.reset();
            http_metric.reset();

            cpu_metric.addValue(0.5 + (rand() % 100) / 100.0);

            for (int j = 0; j < (rand() % 50); ++j) {
                http_metric.increment();
            }

            double memory_usage = 100 + (rand() % 200);
            mem_metric.setUsage(memory_usage);

            storage.store(cpu_metric, http_metric, mem_metric);
        }
        cout << "Metrics written to metrics.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Exception in main: " << e.what() << endl;
        return 1;
    }
}
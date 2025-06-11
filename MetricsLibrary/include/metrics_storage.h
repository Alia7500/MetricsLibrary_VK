#ifndef METRICS_STORAGE_H
#define METRICS_STORAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "cpu_usage_metric.h"
#include "http_request_count_metric.h"
#include "memory_usage_metric.h"

class MetricsStorage {
public:
    MetricsStorage(const std::string& filename);
    ~MetricsStorage();
    void store(const CpuUsageMetric& cpuMetric, const HttpRequestCountMetric& httpMetric, const MemoryUsageMetric& memMetric);

private:
    std::string filename_;
    std::ofstream outfile_;

    std::string getCurrentTimestamp();
};

#endif
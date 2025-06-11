#include "metrics_storage.h"

MetricsStorage::MetricsStorage(const std::string& filename) : filename_(filename) {
    outfile_.open(filename_, std::ios::app);
    if (!outfile_.is_open()) {
        std::cerr << "Error opening file: " << filename_ << std::endl;
        throw std::runtime_error("Failed to open metrics file: " + filename_);
    }
}

MetricsStorage::~MetricsStorage() {
    outfile_.close();
}

void MetricsStorage::store(const CpuUsageMetric& cpuMetric, const HttpRequestCountMetric& httpMetric, const MemoryUsageMetric& memMetric) {
    outfile_ << getCurrentTimestamp() << " " << cpuMetric.toString() << " " << httpMetric.toString() /*<< " " << memMetric.toString()*/ << std::endl;
}

std::string MetricsStorage::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

    std::tm timeinfo;
#ifdef _MSC_VER
    localtime_s(&timeinfo, &now_c);
#else
    localtime_r(&now_c, &timeinfo);
#endif

    std::stringstream ss;
    ss << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
    ss << "." << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}
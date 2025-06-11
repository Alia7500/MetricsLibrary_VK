#include "memory_usage_metric.h"

MemoryUsageMetric::MemoryUsageMetric(const std::string& name) : TypedMetric<double>(name) {}

void MemoryUsageMetric::setUsage(double usage) { value_ = usage; }

std::string MemoryUsageMetric::toString() const {
    return "\"" + getName() + "\" " + getValueAsString();
}
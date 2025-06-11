#include "cpu_usage_metric.h"

CpuUsageMetric::CpuUsageMetric(const std::string& name) : TypedMetric<double>(name) {}

void CpuUsageMetric::addValue(double value) { value_ += value; }

std::string CpuUsageMetric::toString() const {
    return "\"" + getName() + "\" " + getValueAsString();
}
#ifndef MEMORY_USAGE_METRIC_H
#define MEMORY_USAGE_METRIC_H

#include "metric.h"

class MemoryUsageMetric : public TypedMetric<double> {
public:
    MemoryUsageMetric(const std::string& name);
    void setUsage(double usage);
    std::string toString() const override;
};

#endif

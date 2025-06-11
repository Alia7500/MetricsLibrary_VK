#ifndef CPU_USAGE_METRIC_H
#define CPU_USAGE_METRIC_H

#include "metric.h"

class CpuUsageMetric : public TypedMetric<double> {
public:
    CpuUsageMetric(const std::string& name);
    void addValue(double value);
    std::string toString() const override;
};

#endif
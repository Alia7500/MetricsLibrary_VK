#ifndef HTTP_REQUEST_COUNT_METRIC_H
#define HTTP_REQUEST_COUNT_METRIC_H

#include "metric.h"

class HttpRequestCountMetric : public TypedMetric<int> {
public:
    HttpRequestCountMetric(const std::string& name);
    void increment();
    void reset() override;
    std::string toString() const override;
};

#endif

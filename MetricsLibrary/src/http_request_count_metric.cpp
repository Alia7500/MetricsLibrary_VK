#include "http_request_count_metric.h"

HttpRequestCountMetric::HttpRequestCountMetric(const std::string& name) : TypedMetric<int>(name) {}

void HttpRequestCountMetric::increment() { value_++; }

void HttpRequestCountMetric::reset() { value_ = 0; }

std::string HttpRequestCountMetric::toString() const {
    return "\"" + getName() + "\" " + getValueAsString();
}
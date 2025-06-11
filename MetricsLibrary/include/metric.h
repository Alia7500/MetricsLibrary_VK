#ifndef METRIC_H
#define METRIC_H

#include <string>
#include <sstream>

class MetricsStorage; 

class Metric {
public:
    virtual ~Metric() = default;
    virtual std::string getName() const = 0;
    virtual std::string getValueAsString() const = 0;
    virtual void reset() = 0;
    virtual std::string toString() const = 0;
};

template <typename T>
class TypedMetric : public Metric {
public:
    TypedMetric(const std::string& name) : name_(name), value_(0) {}

    std::string getName() const override { return name_; }

    std::string getValueAsString() const override {
        std::stringstream ss;
        ss << value_;
        return ss.str();
    }

    void reset() override { value_ = 0; }

    T getValue() const { return value_; }
    void setValue(T value) { value_ = value; }

protected:
    std::string name_;
    T value_;
};

#endif

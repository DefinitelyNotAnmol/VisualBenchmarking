#pragma once

#include <iostream>
#include <string>
#include <chrono>

class InstrumentationTimer {
    const char* m_Name;
    std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
    bool m_Stopped;
public:
    InstrumentationTimer(const char* name)
        : m_Name(name), m_Stopped(false) {

        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer() {
        if (!m_Stopped)
            Stop();
    }

    void Stop() {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        std::cout << end - start << std::endl;

        m_Stopped = true;
    }
};
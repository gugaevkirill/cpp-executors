#pragma once

#include <string>
#include <functional>
#include <vector>

namespace Executors {

class ThreadPoolExecutor {
    public:
        template <typename TArgs, typename TRes>
        std::vector<TRes> map(
            std::function<TRes(TArgs)> task,
            std::vector<TArgs> args
        ) {
            std::vector<TRes> results;

            for (auto arg : args) {
                results.push_back(task(arg));
            }
            return results;
        }
};



}

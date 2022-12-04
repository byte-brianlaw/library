#include <cstddef>
#include <functional>

template <typename T, typename Hash = std::hash<typename T::value_type>>
class ContainerHash {

private:

    static const auto hash_t = Hash();

public:

    auto operator()(const T& container) const {

        auto result = 0llu;

        for (const auto& x : container) {
            result ^= hash_t(x) + (result << 6) + (result >> 2) + 0x9e3779b97f4a7c15ll;
        }

        return static_cast<std::size_t>(result);

    }

};
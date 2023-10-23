#ifndef EKIZU_SNOWFLAKE_HPP
#define EKIZU_SNOWFLAKE_HPP

#include <ekizu/export.h>
#include <ekizu/util.hpp>
#include <fmt/core.h>
#include <nlohmann/json_fwd.hpp>

namespace ekizu
{
/**
 * @brief Represents a Discord Snowflake, the unique identifier for all Discord
 * resources.
 */
struct Snowflake {
	struct HashFunction {
		size_t operator()(Snowflake s) const
		{
			return std::hash<uint64_t>{}(s.id);
		}
	};

	bool operator==(Snowflake other) const
	{
		return id == other.id;
	}

	/**
     * @brief Returns the timestamp of the Snowflake.
     *
     * @param s The Snowflake to get the timestamp of.
     * @return uint64_t The timestamp of the Snowflake.
     */
	[[nodiscard]] static uint64_t timestamp(Snowflake s)
	{
		return (s.id >> 22) + 1420070400000; // NOLINT
	}

	uint64_t id{};
};

EKIZU_EXPORT void to_json(nlohmann::json &j, const Snowflake &s);
EKIZU_EXPORT void from_json(const nlohmann::json &j, Snowflake &s);
} // namespace ekizu

template <> class fmt::formatter<ekizu::Snowflake> {
    public:
	constexpr auto parse(format_parse_context &ctx)
	{
		return ctx.begin();
	}
	template <typename Context>
	constexpr auto format(ekizu::Snowflake const &s, Context &ctx) const
	{
		return format_to(ctx.out(), "{}", s.id);
	}
};

#endif // EKIZU_SNOWFLAKE_HPP

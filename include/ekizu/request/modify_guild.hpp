#ifndef EKIZU_REQUEST_MODIFY_GUILD_HPP
#define EKIZU_REQUEST_MODIFY_GUILD_HPP

#include <ekizu/guild.hpp>
#include <ekizu/http.hpp>

namespace ekizu {
struct ModifyGuildFields {
	std::optional<std::string> name;
	std::optional<std::string> region;
	std::optional<VerificationLevel> verification_level;
	std::optional<DefaultMessageNotificationLevel>
		default_message_notifications;
	std::optional<ExplicitContentFilter> explicit_content_filter;
	std::optional<Snowflake> afk_channel_id;
	std::optional<uint64_t> afk_timeout;
	std::optional<std::string> icon;
	std::optional<Snowflake> owner_id;
	std::optional<std::string> splash;
	std::optional<std::string> discovery_splash;
	std::optional<std::string> banner;
	std::optional<Snowflake> system_channel_id;
	std::optional<SystemChannelFlags> system_channel_flags;
	std::optional<Snowflake> rules_channel_id;
	std::optional<Snowflake> public_updates_channel_id;
	std::optional<std::string> preferred_locale;
	std::optional<std::vector<std::string>> features;
	std::optional<std::string> description;
	std::optional<bool> premium_progress_bar_enabled;
	std::optional<Snowflake> safety_alerts_channel_id;
};

EKIZU_EXPORT void to_json(nlohmann::json &j, const ModifyGuildFields &f);
EKIZU_EXPORT void from_json(const nlohmann::json &j, ModifyGuildFields &f);

struct ModifyGuild {
	ModifyGuild(
		const std::function<Result<net::HttpResponse>(
			net::HttpRequest, const asio::yield_context &)> &make_request,
		Snowflake guild_id);

	operator net::HttpRequest() const;

	ModifyGuild &afk_channel_id(Snowflake afk_channel_id) {
		m_fields.afk_channel_id = afk_channel_id;
		return *this;
	}

	ModifyGuild &afk_timeout(uint64_t afk_timeout) {
		m_fields.afk_timeout = afk_timeout;
		return *this;
	}

	ModifyGuild &banner(std::string_view banner) {
		m_fields.banner = banner;
		return *this;
	}

	ModifyGuild &default_message_notifications(
		DefaultMessageNotificationLevel default_message_notifications) {
		m_fields.default_message_notifications = default_message_notifications;
		return *this;
	}

	ModifyGuild &description(std::string_view description) {
		m_fields.description = description;
		return *this;
	}

	ModifyGuild &discovery_splash(std::string_view discovery_splash) {
		m_fields.discovery_splash = discovery_splash;
		return *this;
	}

	ModifyGuild &explicit_content_filter(
		ExplicitContentFilter explicit_content_filter) {
		m_fields.explicit_content_filter = explicit_content_filter;
		return *this;
	}

	ModifyGuild &features(const std::vector<std::string> &features) {
		m_fields.features = features;
		return *this;
	}

	ModifyGuild &icon(std::string_view icon) {
		m_fields.icon = icon;
		return *this;
	}

	ModifyGuild &name(std::string_view name) {
		m_fields.name = name;
		return *this;
	}

	ModifyGuild &owner_id(Snowflake owner_id) {
		m_fields.owner_id = owner_id;
		return *this;
	}

	ModifyGuild &preferred_locale(std::string_view preferred_locale) {
		m_fields.preferred_locale = preferred_locale;
		return *this;
	}

	ModifyGuild &premium_progress_bar_enabled(
		bool premium_progress_bar_enabled) {
		m_fields.premium_progress_bar_enabled = premium_progress_bar_enabled;
		return *this;
	}

	ModifyGuild &public_updates_channel_id(
		Snowflake public_updates_channel_id) {
		m_fields.public_updates_channel_id = public_updates_channel_id;
		return *this;
	}

	ModifyGuild &region(std::string_view region) {
		m_fields.region = region;
		return *this;
	}

	ModifyGuild &rules_channel_id(Snowflake rules_channel_id) {
		m_fields.rules_channel_id = rules_channel_id;
		return *this;
	}

	ModifyGuild &safety_alerts_channel_id(Snowflake safety_alerts_channel_id) {
		m_fields.safety_alerts_channel_id = safety_alerts_channel_id;
		return *this;
	}

	ModifyGuild &splash(std::string_view splash) {
		m_fields.splash = splash;
		return *this;
	}

	ModifyGuild &system_channel_flags(SystemChannelFlags system_channel_flags) {
		m_fields.system_channel_flags = system_channel_flags;
		return *this;
	}

	ModifyGuild &system_channel_id(Snowflake system_channel_id) {
		m_fields.system_channel_id = system_channel_id;
		return *this;
	}

	ModifyGuild &verification_level(VerificationLevel verification_level) {
		m_fields.verification_level = verification_level;
		return *this;
	}

	EKIZU_EXPORT Result<Guild> send(const asio::yield_context &yield) const;

   private:
	Snowflake m_guild_id;
	ModifyGuildFields m_fields;
	std::function<Result<net::HttpResponse>(
		net::HttpRequest, const asio::yield_context &)>
		m_make_request;
};
}  // namespace ekizu

#endif	// EKIZU_REQUEST_MODIFY_GUILD_HPP

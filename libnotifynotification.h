#ifndef LIBNOTIFY_NOTIFICATION
#define LIBNOTIFY_NOTIFICATION

#include <string>
#include <libnotify/notify.h>

class LibnotifyNotification {
	public:
		LibnotifyNotification(const std::string& summary, const std::string& body = "", const std::string& icon = "");
		~LibnotifyNotification();
		bool update(const std::string& summary, const std::string& body = "", const std::string& icon = "");
		bool show(GError** error = nullptr);
		void setAppName(const std::string& appName);
		void setTimeout(const int& timeout);
		void setCategory(const std::string& category);
		void setUrgency(const NotifyUrgency& urgency);
		void setImageFromPixbuf(GdkPixbuf* pixbuf);
		void setHint(const std::string& key, GVariant* value = nullptr);
		void clearHints();
		void addAction(const std::string& action, const std::string& label, NotifyActionCallback callback, gpointer user_data = nullptr, GFreeFunc freefunc = nullptr);
		void clearActions();
		bool close(GError** = nullptr);
		int getClosedReason();

		std::string appName() const;
		std::string body() const;
		int closedReason() const;
		std::string iconName() const;
		int id() const;
		std::string summary() const;

	private:
		NotifyNotification* notification;
};

#endif

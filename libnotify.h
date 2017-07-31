#ifndef LIBNOTIFY_H
#define LIBNOTIFY

#include <string>
#include <libnotify/notify.h>

class Libnotify {
	public:
		Libnotify(const std::string& appName);
		~Libnotify();
		bool isInitted();
		std::string getAppName();
		void setAppName(const std::string& name);
		GList* getServerCaps();
		bool getServerInfo(std::string& retName, std::string& retVendor, std::string& retVersion, std::string& retSpecialVersion);
};

#endif

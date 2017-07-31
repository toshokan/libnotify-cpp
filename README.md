# libnotify-cpp

C++ bindings from Libnotify from GNOME.
These bindings help to make the use of libnotify more consisted with other C++ code in your project by being object-oriented and making use of RAII and C++11.
`Libnotify` RAII constructor/destructor takes care of background initialization, and `LibnotifyNotification` acts as a Class interface to `NotifyNotification*`. 

These wrappers use `int` and `bool` instead of `gint` and `gboolean`, as well as `std::string` over `gchar*`.

#ifndef ARDUINO_YEELINKLIB_GPSDATAPOINT_H
#define ARDUINO_YEELINKLIB_GPSDATAPOINT_H

#include "yl_data_point.h"

namespace yeelink
{
	struct location
	{
		float lat;
		float lng;
	};

	class yl_gps_data_point : public yl_data_point
	{
	public:
		yl_gps_data_point();
		yl_gps_data_point(const location &loc, float speed, bool offset, const String &key = String());

		void set_location(const location &loc);
		const location& get_location() const;
		void set_speed(float speed);
		float get_speed() const;
		void set_offset(bool offset);
		bool get_offset() const;

		virtual String to_string() const;

	protected:
		virtual bool from_string_get_value(const String &str);

	private:
		location loc_;
		float speed_;
		bool offset_;
	};

}

#endif

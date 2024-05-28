

class timestamp{

	enum class weekdays{monday, tuesday, wednesday, thursday, friday, saturday, sunday};
	enum class calendar_types{proleptic_julian, julian, gregorian};

	int				year;

	short			month, day, hour, minute, second;

	bool			is_leap;

	weekdays		weekday;

	calendar_types	calendar_type;



public:

	timestamp(void);
	timestamp(int _year, short _month, float _day);

};

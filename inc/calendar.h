

class calendar{
	float	day, second;
	int		year;
	short	month, hour, minute;
	bool	gregorian;

	enum class weekdays{monday, tuesday, wednesday, thursday, friday, saturday, sunday};

public:
	calendar(void);
	calendar(int _year, short _month, float _day);
};


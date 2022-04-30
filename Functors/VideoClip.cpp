#include "VideoClip.h"
#include <stdexcept>
#include <iomanip>

const std::string Date::MONTHS[12] = { "€нвар€", "феврал€", "марта", "апрел€", "ма€", "июн€", "июл€", "августа", "сент€бр€", "окт€бр€", "но€бр€", "декабр€" };

Date::Date(size_t year, size_t month, size_t day) : year{ year }
{
	if (month <= 0 && month > 12)
		throw std::runtime_error("ќшибка! ћес€ц может быть в интервале от 1 до 12" + month);
	this->month = month;

	if (day <= 0 && day > 31)
		throw std::runtime_error("ќшибка! ћес€ц может быть в интервале от 1 до 31" + day);
	this->day = day;
}

std::ostream &operator << (std::ostream &out, const Date &date)
{
	out << std::setfill('0') << date.year << '-'
		<< std::setw(2) << date.month << '-'
		<< std::setw(2) << date.day;
	return out;
}

bool operator < (const Date &date1, const Date &date2)
{
	if (date1.year < date2.year)
		return true;
	else if (date1.year == date2.year && date1.month < date2.month)
		return true;
	else if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)
		return true;
	else
		return false;
}

std::ostream &operator<<(std::ostream &out, const VideoClip &video)
{
	out << '"' << video.name << "\"" << std::endl
		<< "јвтор: " << video.author << std::endl
		<< video.publicationDate << std::endl
		<< " оличество просмотров: " << video.views;
	return out;
}
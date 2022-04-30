#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Date {
	size_t year, month, day;
public:
	static const std::string MONTHS[12];
	Date(size_t year, size_t month, size_t day);

	friend std::ostream &operator << (std::ostream &out, const Date &date);
	friend bool operator < (const Date &date1, const Date &date2);
};

class VideoClip
{
	std::string name, author;
	Date publicationDate;
	int views;
public:
	VideoClip (const std::string &name, const std::string &author, size_t year, size_t month, size_t day, int views) : 
		name {name}, author{author}, publicationDate{year, month, day}, views{views} {}

	friend std::ostream &operator << (std::ostream &out, const VideoClip &video);

	friend class LessName;
	friend class LessAuthor;
	friend class LessDate;
	friend class LessViews;
};

class LessName {
public:
	bool operator () (const VideoClip &video1, const VideoClip &video2) { return video1.name < video2.name; }
};

class LessAuthor {
public:
	bool operator () (const VideoClip &video1, const VideoClip &video2) { return video1.author < video2.author; }
};

class LessDate {
public:
	bool operator () (const VideoClip &video1, const VideoClip &video2) { return video1.publicationDate < video2.publicationDate; }
};

class LessViews {
public:
	bool operator () (const VideoClip &video1, const VideoClip &video2) { return video1.views < video2.views; }
};


#pragma once
#include <iostream>
class Coordinate {
public:
	Coordinate():x(0),y(0){};
	Coordinate(unsigned int _x, unsigned int _y) :x(_x), y(_y) {};
	~Coordinate() {};
	unsigned int getX()const;
	unsigned int getY()const;
protected:
	unsigned int x;
	unsigned int y;
};
class PixelCoordinate: public Coordinate
{
public:
	PixelCoordinate():color(0.0) {};
	PixelCoordinate(unsigned int _x, unsigned int _y, float _color) :Coordinate(_x, _y), color(_color) {};
	PixelCoordinate(const PixelCoordinate& temp);
	PixelCoordinate& operator= (const PixelCoordinate &fraction);
	~PixelCoordinate();
	friend std::ostream& operator<<(std::ostream &out, const PixelCoordinate &pc);
	float getColor()const;
	Coordinate getCoordinate()const ;
private:
	float color;
};
inline bool operator ==(const PixelCoordinate & obj1,const PixelCoordinate & obj2){
	return ((obj1.getX() == obj2.getX()) && (obj1.getY() == obj2.getY()));
}
inline PixelCoordinate::PixelCoordinate(const PixelCoordinate& temp) {
	x = temp.x;
	y = temp.y;
	color = temp.color;
}
inline 	unsigned int Coordinate::getX()const {
	return x;
}
inline unsigned int Coordinate::getY() const{
	return y;
}
inline float PixelCoordinate::getColor() const{
	return color;
}
inline Coordinate PixelCoordinate::getCoordinate()const {
	return Coordinate(x, y);
}
inline bool operator< (const PixelCoordinate & pc1, const PixelCoordinate & pc2){
	if (pc1.getX() < pc2.getX())
		return true;
	else if (pc1.getX() > pc2.getX())
		return false;
	return (pc1.getY() < pc2.getY());
}
inline std::ostream & operator << (std::ostream &out, const PixelCoordinate &pc)
{
	out << "( " << pc.getX() << ", " << pc.getY() << ", " << pc.getColor() << " )" << std::endl;
	return out;
}
inline PixelCoordinate& PixelCoordinate::operator= (const PixelCoordinate &temp) {
	x = temp.x;
	y = temp.y;
	color = temp.color;
}
namespace std
{
	template<>
	struct hash<PixelCoordinate>
	{
		size_t
		operator()(const PixelCoordinate & obj) const
		{
			size_t hash = obj.getX() + 10 * obj.getY();
			return hash;
		}
	};
}
template<typename TYPE>
class Vector3
{
public:
	Vector3(TYPE _x, TYPE _y, TYPE _z){ x = _x, y = _y, z = _z; }
	~Vector3(){}


	Vector3(const Vector3 &obj) {
		x = obj.x;
		y = obj.y;
		z = obj.z;
	}

private:
	TYPE x, y, z;
};


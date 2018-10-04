#include "vectorMath.h"
#include <math.h>

Vector2 operator*(int i, Vector2 v) {
	Vector2 vec = { v.x*i, v.y*i };
	return vec;
}
Vector2 operator+(Vector2 va, Vector2 vb) {
	Vector2 vec = { va.x + vb.x, va.y + vb.y };
	return vec;
}
Vector2 operator+(float i, Vector2 v) {
	Vector2 vec = { v.x + i, v.y + i };
	return vec;
}
Vector2 operator+(Vector2 v, float i) {
	Vector2 vec = { v.x + i, v.y + i };
	return vec;
}
Vector2 operator*(Vector2 v, float i) {
	Vector2 vec = { v.x * i, v.y * i };
	return vec;
}
float dotProduct(Vector2 va, Vector2 vb) {
	return (va.x*vb.x) + (va.y*vb.y);
}
Vector3 operator*(int i, Vector3 v) {
	Vector3 vec = { v.x*i, v.y*i, v.z*i };
	return vec;
}
Vector3 operator+(Vector3 va, Vector3 vb) {
	Vector3 vec = { va.x + vb.x, va.y + vb.y, va.z + vb.z };
	return vec;
}
Vector3 operator+(float i, Vector3 v) {
	Vector3 vec = { v.x + i, v.y + i, v.z + i };
	return vec;
}
Vector3 operator+(Vector3 v, float i) {
	Vector3 vec = { v.x + i, v.y + i, v.z + i };
	return vec;
}
Vector3 operator*(Vector3 v, float i) {
	Vector3 vec = { v.x * i, v.y * i, v.z * i };
	return vec;
}
float dotProduct(Vector3 va, Vector3 vb) {
	return (va.x*va.x) + (va.y*va.y) + (va.z*va.z);
}
float dist(Vector2 va, Vector2 vb) {
	return sqrt(pow(va.x - vb.x, 2) + pow(va.y - vb.y, 2));
}
Vector2 b2Vec2toVector2(b2Vec2 v) {
	return { v.x, v.y };
}
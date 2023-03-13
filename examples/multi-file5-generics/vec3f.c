#include <stdio.h>

#include "vec3f.h"

impl source Vec3<float>
{
	Vec3<float> new(float x, float y, float z)
	{
		Vec3<float> *v = (Vec3<float> *) malloc(sizeof(Vec3<float>));

		v->x = x;
		v->y = y;
		v->z = z;

		return v;
	}

	// fn new(x: float, y: float, z: float) -> Vec3<float>
	// {
	// 	Vec3 { x, y, z }
	// }
}

// impl source Vec3f {
// 	fn new(x: f32, y: f32, z: f32) -> Vec3f {
// 		Vec3f { x, y, z }
// 	}
// }

// impl source Vec3f {
// 	fn add(&self, other: &Vec3f) -> Vec3f {
// 		Vec3f {
// 			x: self.x + other.x,
// 			y: self.y + other.y,
// 			z: self.z + other.z,
// 		}
// 	}
// }

#include <quaternion.h> 

double quaternion::square(double a){
	
	return a*a;
}

quaternion::quaternion(){
	v.x=0.0;
	v.y=0.0;
	v.z=0.0;
	w=0.0;
}

quaternion::quaternion(double angle, vector v_val){
	
	angle=angle*pi/180.0;
	
	v.x=v_val.x*sin(angle/2.0);
	v.y=v_val.y*sin(angle/2.0);
	v.z=v_val.z*sin(angle/2.0);
}

quaternion::quaternion(vector v_val){
	w=0.0;
	v=v_val;
}

quaternion quaternion::normalize(){
	quaternion q;
	double length=sqrt(square(w)+square(v.x)+square(v.y)+square(v.z));
	q.w=w/(length*1.0);
	q.v.x=v.x/(length*1.0);
    q.v.y=v.y/(length*1.0);
	q.v.z=v.z/(length*1.0);
	
	return q;
	
}
quaternion quaternion::conj(){
	quaternion q;
	q.v.x=-1.0*v.x;
	q.v.y=-1.0*v.y;
	q.v.z=-1.0*v.z;
	
	return q;
   }

double quaternion::length(){
	return(sqrt(square(w)+square(v.x)+square(v.y)+square(v.z)));
}


quaternion quaternion::inverse(){
	quaternion q;
	q.w=w;
	q.v.x=v.x;
	q.v.y=v.y;
	q.v.z=v.z;
	
	q=q.conj();
	
	double leng=square(q.length());
	q.w/=(leng*1.0);
	q.v.x/=(leng*1.0);
	q.v.y/=(leng*1.0);
	q.v.z/=(leng*1.0);
	
	return q;
}

quaternion quaternion::operator+(quaternion q){
	quaternion a;
	a.w=w+q.w;
	a.v.x=v.x+q.v.x;
	a.v.y=v.y+q.v.y;
	a.v.z=v.z+q.v.z;
	
	return a;
}

quaternion quaternion::operator-(quaternion q){
	quaternion a;
	a.w=w-q.w;
	a.v.x=v.x-q.v.x;
	a.v.y=v.y-q.v.y;
	a.v.z=v.z-q.v.z;
	
	return a;
}

quaternion quaternion::operator^(double b){
	quaternion a;
	a.w=w*b;
	a.v.x=v.x*b;
	a.v.y=v.y*b;
	a.v.z=v.z*b;

	return a;
}

quaternion quaternion::operator*(quaternion one){
	
	quaternion q;
	
	q.w=w*one.w-v.x*one.v.x-v.y*one.v.y-v.z*one.v.z;
	q.v.x=w*one.v.x+v.x*one.w+v.y*one.v.z-v.z*one.v.y;
	q.v.y=w*one.v.y - v.x*one.v.z + v.y*one.w - v.z*one.v.x;
	q.v.y=w*one.v.z - v.x*one.v.y + v.y*one.v.x - v.z*one.w;
	
	return q;
}












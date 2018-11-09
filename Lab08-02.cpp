# include<iostream>
# include<string>
using namespace std;

class Shapes
{
	protected:
		int length;
		int width;
		
	public:
		Shapes()
		{
			length = 0;
			width = 0;
		}
		
		Shapes(int l, int w)
		{
			length = l;
			width = w;
		}
		
		void setLength(int l)
		{
			length = l;
			return;
		}
		
		int getLength()
		{
			return length;
		}

		void setWidth(int w)
		{
			width = w;
			return;
		}
		
		int getWidth()
		{
			return width;
		}
		
		double area()
		{
			return (length * width);
		}
		
		void printShapes()
		{
			cout << "Lenght: " << length <<
			'\n' << "Width: " << width << 
			endl;
			
			return;
		}
};

class d2_shapes: public Shapes
{
	public:
		d2_shapes(int l, int w):Shapes(l, w)
		{
		}
};

class d3_shapes: public Shapes
{
	protected:
		int height;
		
	public:
		d3_shapes()
		{
			height = 0;
		}
		
		d3_shapes(int l, int w, int h):Shapes(l, w)
		{
			height = h;
		}
		
		double volume()
		{
			return (area() * height);
		}
		
		void setHeight(int h)
		{
			height = h;	
		}
		
		int getHeight()
		{
			return height;	
		}

		void printShape()
		{
			printShapes();
			cout << "Height: " << height << endl;
		}
};

class Circle: public d2_shapes
{
	protected:
		string color;
	
	public:
		Circle()
		{
			color = "";	
		}
		
		Circle(int r, string c):d2_shapes(r, r)
		{
			color = c;
		}
		
		void setColor(string c)
		{
			color = c;
		}
		
		string getColor()
		{
			return color;
		}
		
		void printCircle()
		{
			printShapes();
			cout << "Color: " << color << endl;
			return;
		}
};

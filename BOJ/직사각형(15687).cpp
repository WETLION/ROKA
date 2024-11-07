#include <iostream>

// 15687번 직사각형 

using namespace std;

//class Rectangle{
//	public:
//		Rectangle(int width, int height) {
//			set_width(width);
//			set_height(height);
//		}
//		int get_width() { return width; }
//		int get_height() { return height; }
//		void set_width(int width) {
//			if(0 < width && width <= 1000) width = width;
//		}
//		void set_height(int height) {
//			if(0 < height && height <= 1000) height = height;
//		}
//		int area() { return width * height; }
//		int perimeter() { return 2 * (width + height); }
//		bool is_square() { return width == height; }
//	private:
//		int width, height;
//};
//class Rectangle{
//	public:
//		Rectangle(int width, int height) {
//			set_width(width);
//			set_height(height);
//		}
//		int get_width() { return width; }
//		int get_height() { return height; }
//		void set_width(int width) {
//			if(0 < width && width <= 1000) this -> width = width;
//		}
//		void set_height(int height) {
//			if(0 < height && height <= 2000) this -> height = height;
//		}
//		int area() { return width * height; }
//		int perimeter() { return 2 * (width + height); }
//		bool is_square() { return width == height; }
//	private:
//		int width, height;
//};

class Rectangle {
    private:
        int width, height;
    public:
        Rectangle(int width, int height) {
          set_width(width);
      set_height(height);
        }
        int get_width() const {
          return width;
        }
        int get_height() const {
          return height;
        }
        void set_width(int width) {
          if(0 < width && width <= 1000) this -> width = width;
        }
        void set_height(int height) {
          if(0 < height && height <= 2000) this -> height = height;
        }
        int area() const {
          return width * height;
        }
        int perimeter() const {
          return 2 * (width + height);
        }
        bool is_square() const {
          if(width == height) return true;
          return false;
        }
};

int n;

int main() {
  Rectangle r(1, 1);
  cout << r.get_width() << " " << r.get_height() << " " << r.area() << " " << r.perimeter() << " " << r.is_square() << endl;
  r.set_height();
  r.set_width();
  cout << r.get_width() << " " << r.get_height() << " " << r.area() << " " << r.perimeter() << " " << r.is_square() << endl;
  cin >> n;

  return 0;
}
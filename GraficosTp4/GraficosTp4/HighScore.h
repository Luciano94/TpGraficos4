#include <list>
#include <iostream>
using namespace std;
namespace HighScore {
	class HS {
		struct score
		{
			int point;
			string name;
			bool operator<(const score &rhs) const { return  point > rhs.point; }
		};
		list<score>* _HS;
	public:
		HS();
		~HS();
		void addHS(const int point, const string name);
		void getMin(int &point, string &name);
		void getMax(int &point, string &name);
		int getCant();
		bool getScore(const int pos, int &point, string &name);
		void clearScore();
		list<int>* getPoints();
		list<string>* getNames();
	};
}


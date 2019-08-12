#define eps 0.000001
class Point
{
public:
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
	Point operator + (Point a)
	{
		return Point(a.x + x, a.y + y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	bool operator < (const Point& a) const
	{
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}
};
double cross(Point a, Point b)//叉积
{
	return a.x * b.y - a.y * b.x;
}

double dot(Point a, Point b)//点积
{
	return a.x * b.x + a.y * b.y;
}

bool isclock(Point p0, Point p1, Point p2)
{
	Point a = p1 - p0;
	Point b = p2 - p0;
	if (cross(a, b) < -eps) return true;
	return false;
}

double getDistance(Point a, Point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

typedef vector<Point> Polygon;
Polygon andrewScan(Polygon s)
{
	Polygon u, l;
	if (s.size() < 3) return s;
	sort(s.begin(), s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[s.size() - 1]);
	l.push_back(s[s.size() - 2]);
	for (int i = 2; i < s.size(); i++)//构造凸包上部
	{
		for (int n = u.size(); n >= 2 && isclock(u[n - 2], u[n - 1], s[i]) != true; n--)
		{
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	for (int i = s.size() - 3; i >= 0; i--)//构造凸包下部
	{
		for (int n = l.size(); n >= 2 && isclock(l[n - 2], l[n - 1], s[i]) != true; n--)
		{
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	for (int i = 1; i < u.size() - 1; i++) l.push_back(u[i]);
	return l;
}
int main()
{
	int n;
	scanf("%d", &n);
	Polygon vec;
	for (int i = 0;i < n;i++)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		vec.push_back({ a,b });
	}
	vec = andrewScan(vec);
	double ans = 0;
	for (int i = 1;i < vec.size();i++)
	{
		ans += getDistance(vec[i - 1], vec[i]);
	}
	ans += getDistance(vec[vec.size() - 1], vec[0]);
	printf("%.2lf", ans);
}

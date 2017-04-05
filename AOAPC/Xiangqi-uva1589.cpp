/**/
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

struct Pos
{
	Pos(int y, int x) : y_(y), x_(x) {}
	int y_;
	int x_;
};

struct Piece
{
	Piece() : p_(0, 0) {}
	char name_;
	Pos p_;
};

Piece general;
std::vector<Piece> white(10);

std::vector<Pos> threat_pos(Piece p)
{
	std::vector<Pos> ps;
	//std::set<Pos> area;
	//for (int y = 1; y <= 3; ++y)
		//for (int x = 4; x <= 6; ++x)
			//area.insert(Pos(y, x));

	switch (p.name_)
	{
	case 'G':
		ps.push_back(Pos(1, p.p_.x_));
		ps.push_back(Pos(2, p.p_.x_));
		ps.push_back(Pos(3, p.p_.x_));
		break;
	case 'R':
		if (p.p_.x_ >= 4 && p.p_.x_ <= 6 && p.p_.y_ >= 1 && p.p_.y_ <= 3)
		{
			if (p.p_.x_ == 4 && p.p_.y_ == 1)
			{
				ps.push_back(Pos(1, 5));
				ps.push_back(Pos(1, 6));
				ps.push_back(Pos(2, 4));
				ps.push_back(Pos(3, 4));
			}
			else if (p.p_.x_ == 5 && p.p_.y_ == 1)
			{
				ps.push_back(Pos(1, 4));
				ps.push_back(Pos(1, 6));
				ps.push_back(Pos(2, 5));
				ps.push_back(Pos(3, 5));
			}
			else if (p.p_.x_ == 6 && p.p_.y_ == 1)
			{
				ps.push_back(Pos(1, 5));
				ps.push_back(Pos(1, 4));
				ps.push_back(Pos(2, 6));
				ps.push_back(Pos(3, 6));
			}
			else if (p.p_.x_ == 6 && p.p_.y_ == 2)
			{
				ps.push_back(Pos(1, 6));
				ps.push_back(Pos(3, 6));
				ps.push_back(Pos(2, 5));
				ps.push_back(Pos(2, 4));
			}
			else if (p.p_.x_ == 6 && p.p_.y_ == 3)
			{
				ps.push_back(Pos(3, 4));
				ps.push_back(Pos(3, 5));
				ps.push_back(Pos(2, 6));
				ps.push_back(Pos(1, 6));
			}
			else if (p.p_.x_ == 5 && p.p_.y_ == 3)
			{
				ps.push_back(Pos(1, 5));
				ps.push_back(Pos(2, 5));
				ps.push_back(Pos(3, 4));
				ps.push_back(Pos(3, 6));
			}
			else if (p.p_.x_ == 4 && p.p_.y_ == 3)
			{
				ps.push_back(Pos(3, 5));
				ps.push_back(Pos(3, 6));
				ps.push_back(Pos(2, 4));
				ps.push_back(Pos(1, 4));
			}
			else if (p.p_.x_ == 4 && p.p_.y_ == 2)
			{
				ps.push_back(Pos(1, 4));
				ps.push_back(Pos(2, 5));
				ps.push_back(Pos(2, 6));
				ps.push_back(Pos(3, 4));
			}
			else
			{
				ps.push_back(Pos(1, 5));
				ps.push_back(Pos(2, 4));
				ps.push_back(Pos(2, 6));
				ps.push_back(Pos(3, 5));
			}
		}
		else if (p.p_.x_ >= 4 && p.p_.x_ <= 6)
		{
			ps.push_back(Pos(1, p.p_.x_));
			ps.push_back(Pos(2, p.p_.x_));
			ps.push_back(Pos(3, p.p_.x_));
		}
		else if (p.p_.y_ >= 1 && p.p_.y_ <= 3)
		{
			ps.push_back(Pos(p.p_.y_, 4));
			ps.push_back(Pos(p.p_.y_, 5));
			ps.push_back(Pos(p.p_.y_, 6));
		}
		break;
	case 'C':
		if (p.p_.x_ >= 4 && p.p_.x_ <= 6)
		{
			for (auto& f : white)
			{
				if (f.p_.x_ == p.p_.x_ && f.p_.y_ <= p.p_.y_)
				{
					int i;
					if (f.p_.y_ <= 3)
						i = f.p_.y_ - 1;
					else
						i = 3;
					while (i-- > 0)
						ps.push_back(Pos(i, p.p_.x_));
				}
			}
		  
		}
		else if (p.p_.y_ >= 1 && p.p_.y_ <= 3)
		{
			if (p.p_.x_ <= 4)
			{
				for (auto& f : white)
				{
					if (f.p_.y_ == p.p_.y_ && f.p_.x_ > p.p_.x_)
					{
						int i;
						if (f.p_.x_ >= 4)
							i = f.p_.x_ + 1;
						else
							i = 4;
						for (; i <= 6; ++i)
							ps.push_back(Pos(p.p_.y_, i));
					}
				}
			}
			else if (p.p_.x_ >= 6)
			{
				for (auto& f : white)
				{
					if (f.p_.y_ == p.p_.y_ && f.p_.x_ < p.p_.x_)
					{
						int i;
						if (f.p_.x_ <= 6)
							i = f.p_.x_ - 1;
						else
							i = 6;
						for (; i >= 4; --i)
							ps.push_back(Pos(p.p_.y_, i));
					}
				}
			}
		}
		break;
	case 'H':
		std::vector<Pos> d;
		bool hob_o = 0, hob_b = 0, hob_l = 0, hob_r = 0;
		for (auto& f : white)
		{
			if (f.p_.x_ == p.p_.x_)
			{
				if (f.p_.y_ == p.p_.y_ + 1)
					hob_o = 1;
				if (f.p_.y_ == p.p_.y_ - 1)
					hob_b = 1;
			}
			if (f.p_.y_ == p.p_.y_)
			{
				if (f.p_.x_ == p.p_.x_ + 1)
					hob_r = 1;
				if (f.p_.x_ == p.p_.x_ - 1)
					hob_l = 1;
			}
		}
		if (!hob_o && p.p_.y_ >= 3)
		{
			ps.push_back(Pos(p.p_.y_ - 2, p.p_.x_ - 1));
			ps.push_back(Pos(p.p_.y_ - 2, p.p_.x_ + 1));
		}
		if (!hob_b && p.p_.y_ <= 8)
		{
			ps.push_back(Pos(p.p_.y_ + 2, p.p_.x_ - 1));
			ps.push_back(Pos(p.p_.y_ + 2, p.p_.x_ + 1));
		}
		if (!hob_l && p.p_.x_ >= 3)
		{
			ps.push_back(Pos(p.p_.y_ - 1, p.p_.x_ - 2));
			ps.push_back(Pos(p.p_.y_ + 1, p.p_.x_ - 2));
		}
		if (!hob_r && p.p_.x_ <= 7)
		{
			ps.push_back(Pos(p.p_.y_ - 1, p.p_.x_ + 2));
			ps.push_back(Pos(p.p_.y_ + 1, p.p_.x_ + 2));
		}
		break;
	}
	return ps;
}

std::vector<Pos> can_move_to(Piece p)
{
	std::vector<Pos> ps;
	if (p.p_.x_ == 4 && p.p_.y_ == 1)
	{
		ps.push_back(Pos(1, 5));
		ps.push_back(Pos(2, 4));
	}
	else if (p.p_.x_ == 5 && p.p_.y_ == 1)
	{
		ps.push_back(Pos(1, 4));
		ps.push_back(Pos(1, 6));
		ps.push_back(Pos(2, 5));
	}
	else if (p.p_.x_ == 6 && p.p_.y_ == 1)
	{
		ps.push_back(Pos(1, 5));
		ps.push_back(Pos(2, 6));
	}
	else if (p.p_.x_ == 6 && p.p_.y_ == 2)
	{
		ps.push_back(Pos(1, 6));
		ps.push_back(Pos(3, 6));
		ps.push_back(Pos(2, 5));
	}
	else if (p.p_.x_ == 6 && p.p_.y_ == 3)
	{
		ps.push_back(Pos(3, 5));
		ps.push_back(Pos(2, 6));
	}
	else if (p.p_.x_ == 5 && p.p_.y_ == 3)
	{
		ps.push_back(Pos(2, 5));
		ps.push_back(Pos(3, 4));
		ps.push_back(Pos(3, 6));
	}
	else if (p.p_.x_ == 4 && p.p_.y_ == 3)
	{
		ps.push_back(Pos(3, 5));
		ps.push_back(Pos(2, 4));
	}
	else if (p.p_.x_ == 4 && p.p_.y_ == 2)
	{
		ps.push_back(Pos(1, 4));
		ps.push_back(Pos(2, 5));
		ps.push_back(Pos(3, 4));
	}
	else 
	{
		ps.push_back(Pos(1, 5));
		ps.push_back(Pos(2, 4));
		ps.push_back(Pos(2, 6));
		ps.push_back(Pos(3, 5));
	}
	return ps;
}

int main()
{
	int n;
	const char* debug = "1 4\n";
	const char* debug2 = "G 10 5\nR 6 4\n";

	n = 2;
	if (n) //while (sscanf(debug, "%d", &n) == 1 && n)
	{
		sscanf(debug, "%d%d", &general.p_.y_, &general.p_.x_);
		while (n--)
		{
			Piece p;
			scanf(debug2, "%c %d %d", &p.name_, &p.p_.y_, &p.p_.x_);
			white.push_back(p);
		}
		std::vector<Pos> esc = can_move_to(general);
		std::vector<Pos> threat;
		for (auto f : white)
		{
			std::vector<Pos> t = threat_pos(f);
			threat.insert(threat.end(), t.begin(), t.end());
		}
		bool checkmate = 1;
		for (auto e = esc.begin(); e != esc.end(); ++e)
			for (auto t = threat.begin(); t != threat.end(); ++t)
			{
				if (e->x_ == t->x_ && e->y_ == t->y_)
				{
					e->x_ = e->y_ = 0;
					break;
				}
			}
		for (auto& f : esc)
			if (f.x_ != 0 && f.y_ != 0)
				checkmate = 0;
		checkmate ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}
/**/
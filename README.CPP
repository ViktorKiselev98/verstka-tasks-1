#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;
//=========================================================== 1 задание ========================================================
int main()
{
    int i;
    cin >> i;
    while (cin.fail() == 1)
    {
        cout << "error";
        cin.clear(); 
        cin >> i;
    }
  
    cout << i;
// ============================================================= 2 задание ========================================================
    cout << setiosflags(ios::fixed);
    cout << setprecision(2) << 1000.243 << endl;
    cout << setw(20) << "car";
    
    return 0;
}
// ============================================================== 3 задание =========================================================
class Player : public GenericPlayer
{
public:
	Player(const string& name = "");

	virtual ~Player();

	
	virtual bool IsHitting() const;

	
	void Win() const;

	
	void Lose() const;

	
	void Push() const;
};

Player::Player(const string& name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	cout << m_Name << " wins." << endl;
}

void Player::Lose() const
{
	cout << m_Name << " loses." << endl;
}

void Player::Push() const
{
	cout << m_Name << " pushes." << endl;

	//================================================================ 4 задание =============================================

	class House : public GenericPlayer
	{
	public:
		House(const string& name = "House");

		virtual ~House();

		
		virtual bool IsHitting() const;

		// flips over first card
		void FlipFirstCard();
	};

	House::House(const string & name) : GenericPlayer(name)
	{
	}

	House::~House()
	{
	}

	bool House::IsHitting() const
	{
		return (GetTotal() <= 16);
	}

	void House::FlipFirstCard()
	{
		if (!(m_Cards.empty()))
		{
			m_Cards[0]->Flip();
		}
		else
		{
			cout << "No card to flip!" << endl;
		}
	}

//================================================================== 5 задание ================================================================
	ostream& operator<< (ostream& os, const Card& aCard)
	{
		const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
									"10", "J", "Q", "K" };
		const string SUITS[] = { "c", "d", "h", "s" };

		if (aCard.m_IsFaceUp)
		{
			os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
		}
		else
		{
			os << "XX";
		}

		return os;
	}

	
	ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer)
	{
		os << aGenericPlayer.m_Name << ":\t";

		vector<Card*>::const_iterator pCard;
		if (!aGenericPlayer.m_Cards.empty())
		{
			for (pCard = aGenericPlayer.m_Cards.begin();
				pCard != aGenericPlayer.m_Cards.end(); ++pCard)
			{
				os << *(*pCard) << "\t";
			}

			if (aGenericPlayer.GetTotal() != 0)
			{
				os << "(" << aGenericPlayer.GetTotal() << ")";
			}
		}
		else
		{
			os << "<empty>";
		}
		return os;
	}

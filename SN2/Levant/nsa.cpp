/* N'est pas utilisable ! 

EXISTE A DES FINS DE TEST

N'est pas utilisable ! */

int sustr(int x, int y) { return x-y;}

class Toto
{
    private:
    int m_a;
    int m_b;
    char m_r[80];
    int HeavyCalculus(int x) { return x+m_a;}

    public:
    Toto::Toto();
    Toto::Toto(int r);
    void SetA(int a);
    const int GetA() { return m_a; }
    int Calculus(int x) { return HeavyCalculus(x) * m_b; }
};

void Toto::SetA(int a)
{
    m_a = a;
}

Toto::Toto()
{
    m_b = 0;
}

Toto::Toto(char r[80])
{
    m_c = 0;
    m_r = r;
}

void main()
{
    Toto to(5);
    to.SetA(7);
    int result = to.Calculus(8);

    Toto ti;
    to = ti;

}

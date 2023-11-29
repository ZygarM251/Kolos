#pragma once
class Zbior
{
    size_t m_liczbaElementow = 0;
    double* m_elementy = nullptr;
    double m_dolnaGranica = 0;
    double m_gornaGranica = 0;

    void alokuj(int); 
    void zwolnij();

public:
    Zbior(size_t liczElem, double dGran, double gGran);
    ~Zbior() { zwolnij(); }
    Zbior(const Zbior& z);
    Zbior& operator=(const Zbior& z);
    bool operator==(const Zbior& zbior) const;
    bool operator!=(const Zbior& zbior) ;

    Zbior(Zbior&&) = delete;
    Zbior& operator=(Zbior&&) = delete;

    double srednia() const {
        if (m_liczbaElementow == 0) return 0.0;

        double suma = 0.0;
        for (size_t i = 0; i < m_liczbaElementow; ++i) {
            suma += m_elementy[i];
        }
        return suma / m_liczbaElementow;
    }

    bool operator>(const Zbior& other) const {
        return srednia() > other.srednia();
    }

    friend bool operator<(const Zbior& zbior1, const Zbior& zbior2) {
        return zbior1.srednia() < zbior2.srednia();
    }
};
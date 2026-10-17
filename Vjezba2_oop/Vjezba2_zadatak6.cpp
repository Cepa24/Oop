#include <iostream>
#include <string>

struct Student {
	std::string ime;
	std::string JMBAG;
	int godina_studija;
	int ECTS_bodovi;
	double prosjek_ocjena;
};

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)) {
    for (int i = 0;i < n;i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

void ispisi(Student& st) {
    std::cout << st.ime << " " << st.JMBAG << " " << st.godina_studija << " " << st.ECTS_bodovi << " " << st.prosjek_ocjena << std::endl;
}

void povecaj_godinu_studija(Student& st) {
    st.godina_studija++;
}

int main() {
    Student studenti[] = {
        {"Ana Anic",   "36500001", 1, 60, 4.2},
        {"Ivo Ivic",   "36500002", 1,  0, 0.0},
        {"Marko Maric","36500003", 2, 48, 3.4},
        {"Petra Peric","36500004", 1, 30, 3.8},
        {"Luka Lukic", "36500005", 3, 40, 3.5},
        {"Maja Majic", "36500006", 2, 45, 3.9}
    };

    int n = sizeof(studenti) / sizeof(studenti[0]);

    auto polozili_barem_jedan = [](const Student& st) {
        return st.godina_studija==1 && st.ECTS_bodovi > 0;
    };

    auto prosjek_veci_od = [](const Student& st) {
        return st.prosjek_ocjena > 3.5;
    };

    auto barem_45 = [](const Student& st) {
        return st.ECTS_bodovi >= 45;
    };


    std::cout << "Studenti prve godine koji su polozili barem jedan ispit:" << std::endl;
    filter_students(studenti, n, ispisi, polozili_barem_jedan);
    std::cout << "Studenti kojima je prosjek veci od 3.5" << std::endl;
    filter_students(studenti, n, ispisi, prosjek_veci_od);

    filter_students(studenti, n, povecaj_godinu_studija, barem_45);
}
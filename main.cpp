#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Siparis {
    string musteriAdi;
    string urun;
};

queue<Siparis> siparisKuyrugu;

void siparisEkle() {
    Siparis yeniSiparis;
    cin.ignore();
    cout << "Musteri Adi: "; getline(cin, yeniSiparis.musteriAdi);
    cout << "Siparis: "; getline(cin, yeniSiparis.urun);
    siparisKuyrugu.push(yeniSiparis);
    cout << "Siparis eklendi." << endl;
}

void siparisHazirla() {
    if (!siparisKuyrugu.empty()) {
        cout << siparisKuyrugu.front().urun << " hazirlandi." << endl;
        siparisKuyrugu.pop();
   } else {
        cout << "Hazirlanacak siparis yok." << endl;
    }
}

void siparisleriListele() {
    if (siparisKuyrugu.empty()) {
        cout << "Bekleyen siparis yok." << endl;
    } else {
        queue<Siparis> temp = siparisKuyrugu;
        while (!temp.empty()) {
            cout << temp.front().musteriAdi << " - " << temp.front().urun << endl;
            temp.pop();
        }
    }
}

void toplamBekleyenSiparis() {
    cout << "Toplam bekleyen siparis: " << siparisKuyrugu.size() << endl;
}

int main() {
    int secim;
    while (true) {
        cout << endl << "1: Siparis Ekle  2: Siparisi Hazirla  3: Siparisleri Listele  4: Toplam Siparis  5: Cikis" << endl << "> ";
        cin >> secim;

        if (secim == 1) siparisEkle();
        else if (secim == 2) siparisHazirla();
        else if (secim == 3) siparisleriListele();
        else if (secim == 4) toplamBekleyenSiparis();
        else if (secim == 5) { cout << "Cikiliyor..." << endl; break; }
        else cout << "Gecersiz secim!" << endl;
    }

  return 0;
}

}

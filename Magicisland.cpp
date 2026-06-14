#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <cstddef>
#include <unistd.h>

void Sleep(int milliseconds)
{
    usleep(milliseconds * 1000);
}

using namespace std;
string name;

struct PaperChoice {
    string paper;
    string power;
};

const PaperChoice PAPER_LIST[] = {
    {"Dawn", "Flower Spirit (healer)"},
    {"Thorn", "Warrior (Thorned defender)"},
    {"Wave", "Water Mage (fluid combat)"},
    {"Echo", "Echo Shifter (sound & memory)"},
    {"Star", "Star Weaver (light & flight)"}
};
const int NUM_PAPERS = 5;

struct Character {
    string name;
    string paper;
    string power;
    bool memory_loss;
    bool transformed;
    
    Character(string n, string p, string pw, bool ml=false, bool tr = false)
    : name(n), paper(p), power(pw), memory_loss(ml), transformed(tr) {}
    Character() : memory_loss(false), transformed(false) {};

    };

Character team[NUM_PAPERS]; 

void clearScreen();
void wis();
void pauseLine();
void lupakan();
void mencari();
void ending();

void pauseLine() {
    cout << "\n (Tekan ENTER untuk melanjutkan)";
    if (cin.peek() == '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string mapPower(const string &p) {
    if (p == "Dawn") return "Flower Spirit (healer)";
    if (p == "Thorn") return "Warrior (thorned defender)";
    if (p == "Wave") return "Water Mage (fluid combat)";
    if (p == "Echo") return "Echo Shifter (sound & memory)";
    if (p == "Star") return "Star Weaver (light & flight)";
    return "Unknown";
};

int chooseIndex(int maxIndex) {
    int choice;
    while (true) {
        cout << "> ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan angka yang valid.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (choice >= 1 && choice <= maxIndex) return choice - 1; 
        cout << "Pilih antara 1 sampai " << maxIndex << ".\n";
    }
}
void clearScreen ()
{
	system ("cls");
}

void wis() {
    clearScreen();
    cout << "	   				                                                                         \n";
    cout << "					                           ..:.....:..::::-----:.                           \n";
    cout << "					                           ..::-==--::===-:---::--:.                          \n";
    cout << "					                  .   ..    --==++++++*+++=--:::=+---::.                      \n";
    cout << "					                  .:---:.  -=-=====+=:-:-++-::.                    \n";
    cout << "					            ..  ..:-=----. :-=:::-==+====+=---=*+=--: .::.                \n";
    cout << "					          .:--:::....:---:-===-=--------:-+==--:::=+-:-:::---:.               \n";
    cout << "					       ...======--:---::-=*+====-==--===-++=+-----=-:-==---==--:::           \n";
    cout << "					         -++==+==+++====++====++++++===+*+=+=++-::-:==---=+==-:.         \n";
	cout << "					        .=++###+++##+++++++++++++++=-:-++====+#=-:..       \n";
	cout << "					        .=+++#+==######++++=-=++=---++#+==+##+=-::       \n";
    cout << "					       ..-+=+++++++++=-=+++###+---:..-:.:=+##==++*+=-:       \n";
    cout << "					     .:.:-------::-:-====-==+++####=::-++=-++=-:-####+++++*++=-:       \n";
    cout << "					     .--=++=---===---:-=-=-.:--==+%+=++#+=+==###==-.:-===++:       \n";
    cout << "					     .:=++++==++++=-==--=:-+-====#+=+#%%%%##*+=-+-. ..:::==:       \n";
    cout << "					     .-+###++-:.:=++===-=+###-+###%#- -===-::-.:. .::.       \n";
    cout << "					  ..::=#%%#+#---:-+++++=:--.+#==-+##+=:+++==-:=-:-:.  .        \n";
    cout << "					    :=+###++=--====----=++-::::..=##++++-: .=*+=::=====-           \n";
    cout << "				 	    .-=#++==:.:=--==+=+=+##+----:-++#%==+++-.   -==:..=++==-           \n";
    cout << "					    :=====---------::=+++++#####+=====+++= .==-:   .--: .++++-           \n";
    cout << "					    -+===-..-++-----.-++:=+++==+==+++====+++==:    ::..=#*+=..:.       \n";
    cout << "					   .=+-=+=  :=++==+=:-##:.-===+=+++=+++=-::  -++-:::::..=*+=-:.        \n";
    cout << "					     +++=-. .-=++++=.:-++: :-  -+=-=+++=---=-++-=+=---:=++#+=--:     \n";
    cout << "					    :++=.  .:-++-. -+++:  ..-=+=.:+#####---: :::-====+++#=--:    \n";
    cout << "					     -==+=   ..-+++-  -++=  ....-++++-..:-=###%+-::    :--.:=+++=++=-.   \n";
    cout << "					     --=-:    .=++.   =+=   .:::-++=.      +%#*+++.   ::-:  :.:-:.=+++-.   \n";
    cout << "					     .:-.      :--=:   ::= ..:.. -=++-        +%#*===:  .--. .::.:. :+++-    \n";
    cout << "					      :.        ...     :    ..   -==-.        .#%#+=--  ..  .--:--..-==-    \n";
    cout << "					                 .                .::        .-+%%%*=-:  .   .-===-. :--.    \n";
    cout << "					                                   :.     .-=++#-:       .=++*=: ...     \n";
    cout << "					                                        :====++=:.         -++-   .      \n";
    cout << "					                                       -++++#*+.            -+++-          \n";
    cout << "					                                      .=*+++               -++-.         \n";
    cout << "					                                      .+*+==.   .          -==:          \n";
    cout << "					                                  .:. :++#++=....            :.          \n";
    cout << "					                               ...::-=+=++==%+==:....          .           \n";
    cout << "					                              ...:-====+++=+-.                       \n";
    cout << "					                               .    .:--==-::-=-:-:....                      \n";
    cout << "					                                                  .                          \n";
    string loading = "            -              +              x              +              -";

    for (int i = 0; i < loading.length(); i++) {
        cout << loading[i] << flush; 
        Sleep(100);  
    }
    cout << endl;

    pauseLine();

    clearScreen();
}


// Fungsi untuk mendapatkan deskripsi transformasi
void getTransformationDescription(const string& paper) {
    if (paper == "Dawn") {
        cout << "Bangkit aura bunga penyembuh yang lembut.\n";
    } else if (paper == "Thorn") {
        cout << "Tubuh dihiasi duri kokoh dan kekuatan bertahan aktif.\n";
    } else if (paper == "Wave") {
        cout << "Menjadi wujud laut — mengendalikan air dan gelombang pasang.\n";
    } else if (paper == "Echo") {
        cout << "Menjadi entitas gema — bisa memanipulasi suara & ingatan.\n";
    } else if (paper == "Star") {
        cout << "Terangi dengan sepasang sayap kecil bercahaya.\n";
    } else {
        cout << "Transformasi tidak teridentifikasi.\n";
    }
}

void book(){
	system("cls");
	cout << " _________________________________________________________\n";
	cout << "||-------------------------------------------------------||\n";
	cout << "||.--.    .-._                        .----.             ||\n";
	cout << "|||==|____| |H|___            .---.___|""""|_____.--.___ ||\n";
	cout << "|||  |====| | |xxx|_          |+++|=-=|_  _|-=+=-|==|---|||\n";
	cout << "|||==|    | | |   | |         |   |   | || |Black|  | ^ |||\n";
	cout << "|||  |    | | |   || |   .--. |   |=-=|_||_|-=+=-|  | ^ |||\n";
	cout << "|||  |    | | |   |_| |_( oo )|   |   |    |Magus|  | ^ |||\n";
	cout << "|||==|====| |H|xxx|  | | |''| |+++|=-=|""""|-=+=-|==|---|||\n";
	cout << "||`--^----'-^-^---'   `-' ""  '---^---^----^-----^--^---^||\n";
	cout << "||-------------------------------------------------------||\n";
	cout << "||               ___                   .-.__.-----. .---.||\n";
	cout << "||              |===| .---.   __   .---| |XX|<(*)>|_|^^^|||\n";
	cout << "||         ,  /(|   |_|III|__|''|__|:x:|=|  |     |=| Q |||\n";
	cout << "||      _a'{ / (|===|+|   |++|  |==|   | |  |Illum| | R |||\n";
	cout << "||      '/\\/ _( |===|-|   |  |''|  |:x:|=|  |inati| | Y |||\n";
	cout << "||_____  -\{___( |   |-|   |  |  |  |   | |  |     | | Z |||\n";
	cout << "||       _(____)|===|+|[I]|DK|''|==|:x:|=|XX|<(*)>|=|^^^|||\n";
	cout << "||              `---^-^---^--^--'--^---^-^--^-----^-^---^||\n";
	cout << "||-------------------------------------------------------||\n";
	cout << "||_______________________________________________________||\n";
	string loading = "			-			+			x			+				-";

    for (int i = 0; i < loading.length(); i++) {
        cout << loading[i] << flush; 
        Sleep(100);  
    }
    cout << endl;

    pauseLine();

    clearScreen();
}

int main() {
    clearScreen();
    srand((unsigned)time(NULL));
    int keputusan, pilihan, perasaan; 
    
    string chosenFood;
    string chosenDrink;
	cout << "	+			     *****   **    **           *                             +     			\n";
	cout << "				  ******  ***** *****                  -           *               				\n";
	cout << "				 **   *  *  ***** *****                           ***              				\n";
	cout << "				*    *  *   * **  * **          .                  *               			:	\n";
	cout << "		+		    *  *    *     *                                                				\n";
	cout << "				   ** **    *     *        ****        ****      ***        ****   				\n";
	cout << "				   ** **    *     *       * ***  *    *  ***  *   ***      * ***  *			.	\n";
	cout << "				   ** **    *     *      *   ****    *    ****     **     *   **** \n";
	cout << "				   ** **    *     *     **    **    **     **      **    **        				\n";
	cout << "				.  ** **    *     **    **    **    **     **      **    **        		+		\n";
	cout << "				   *  **    *     **    **    **    **     **      **    **     -   				\n";
	cout << "				   *  **    *     **    **    **    **     **      **    **        				\n";
	cout << "	_			   *  **    *     **    **    **    **     **      **    **        				\n";
	cout << "				*  *   **    *     **    **    **    **     **      **    **    			+	\n";
	cout << "				  ****      *      **   **    **    **     **      **    ***     * \n";
	cout << "		*		 *  *****           **   ***** **    ********      *** *  *******  				\n";
	cout << "				*     **                  ***   **     *** ***      ***    *****   				\n";
	cout << "				*                                           ***       *             				\n";
	cout << "				 **               +                   ****   ***                   		-		\n";
	cout << "		.		                                    *******  **                    				\n";
	cout << "				      -                            *     ****                   +   			\n";
	cout << "\n								---ISLAND---" ;
    pauseLine();

    wis();
	cout << "	 __  __                 _                    \n";
    cout << "	|  \/  | __ _ ___ _   _| | ____ _ _ __       \n";
	cout << "	| |\/| |/ _` / __| | | | |/ / _` | '_ \      \n";
	cout << "	| |  | | (_| \__ \ |_| |   < (_| | | | |     \n";
	cout << "	|_|  |_|\__,_|___/\__,_|_|\_\__,_|_| |_|     \n";
	cout << "	 _ __   __ _ _ __ ___   __ _ _ __ ___  _   _ \n";
	cout << "	| '_ \ / _` | '_ ` _ \ / _` | '_ ` _ \| | | |\n";
	cout << "	| | | | (_| | | | | | | (_| | | | | | | |_| |\n"; 
	cout << "	|_| |_|\__,_|_| |_| |_|\__,_|_| |_| |_|\__,_|\n";
	cout << "-------		 Masukan namamu			 -------\n";
	cout << ":";
    cin >> name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    wis();

    cout << "Di suatu hari....\n";
    cout << "Hari minggu. Ada seorang bernama " <<name<< endl;
    cout << "Kamu adalah seorang remaja yanng sedang di tingkat 2 di Kazegawa Science & Research School" << endl;
    cout << "Kamu tinggal sendiri karena, kamu memutuskan memilih sekolah yang cukup jauh dari tempat lahirmu." << endl;
    cout << "Dan karena ini hari minggu kamu memutuskan untuk berolahraga. Yaitu lari pagi." << endl;
    cout << "Setelah beberapa menit atau jam? kamu menggelilingi daerah itu kamu memutuskan untuk sarapan" << endl;
    cout << "Dan memilih satu toko yaitu 'BearBun Cafe'" << endl;

	cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
    cout << "|                       M E N U                                     |\n";
    cout << "|     Menu makanan:                           Menu minuman:         |\n";
    cout << "!     1. Honey garlic bites                   1. Vanilla cloud latte!\n";
    cout << ":     2. Creamy soft roll                     2. Berry spark soda   :\n";
    cout << "|     3. Ramen                                3. Matcha cream float |\n";
    cout << "|                                                                   |\n";
    cout << "'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n";


    // Memilih Makanan
    cout << "Pilih makanan (1-3):\n";
    int foodIdx = chooseIndex(3);

    switch (foodIdx + 1) {
        case 1:
            chosenFood = "Honey garlic bites";
            break;
        case 2:
            chosenFood = "Creamy soft roll";
            break;
        case 3:
            chosenFood = "Ramen";
            break;
        default:
            chosenFood = "Ramen";
            break;
    }

    // Memilih Minuman
    cout << "Pilih minuman (1-3):\n";
    int drinkIdx = chooseIndex(3);

    switch (drinkIdx + 1) {
        case 1:
            chosenDrink = "Vanilla cloud latte";
            break;
        case 2:
            chosenDrink = "Berry spark soda";
            break;
        case 3:
            chosenDrink = "Matcha cream float";
            break;
        default:
            chosenDrink = "Matcha cream float";
            break;
    }


    cout << "\n" << name << " membeli " << chosenFood << " dan " << chosenDrink << ".\n";
    cout << "Mau makan di tempat atau dibawa pulang?\n1) Makan di tempat\n2) Bawa pulang\n";
    
    int tempat = chooseIndex(2); 
    
    pauseLine();

    clearScreen();
    // Jika tempat == 0 (index 0, yaitu pilihan 1: Makan di Tempat)
    if (tempat == 0) {
        // Pilihan: Makan di Tempat
        cout << "\n[PILIHAN: DINE IN]\n";
        cout << name << " memutuskan makan di tempat.\n";
        cout << "Di sela-sela saat " << name<<" makan terjadi suatu getaran.\n";
        cout << "Yap, benar gempa terjadi. Ada notifikasi di hp " << name <<" telah terjadi gempa 5,7 mg.\n";
        cout << "Itu membuat orang disekitar berlari kesana-kemari, tidak terkecuali " << name <<endl;
        cout << name << " berusaha menyelamatkan diri dan tanpa sadar ada tiang listrik yang terjatuh. Dan memimpa tubuhnya...\n";
        cout << "Semua menjadi gelap, lalu... " << name << " tidak sadar.\n";
    } else {
        // Pilihan: Bawa Pulang (index 1)
        cout << "\n[PILIHAN: TAKE AWAY]\n";
        cout << name << " Membawa makanan pulang. Di jalan terjadi GEMPA keras. Peringatan di hpnya menunjukan bahwa telah terjadi gempa sebesar 5,7 mg\n";
        cout << name << " Berhenti sejenak hingga gempa itu mereda.\n";
        cout << "Dan setelah beberapa menit berlalu " <<name<< " sudah sampai di depan rumahnya.\n";
        cout << "Akan tetapi saat " <<name<< " mau masuk terdengar teriakan, suara kendaraan dan orang-orang yang berlarian.\n";
        cout << name << " Di kejauhan melihat ada banyak orang yang berlarian dan berteriak tidak karuan.\n";
        cout << "Sampai " << name << " mendengar satu kata yaitu 'tsunami---'\n";
        cout << name << " kebingungan dan tanpa pikir panjang Ia ingin pergi ke dataran tinggi terdekat seperti orang lain mungkin??\n";
        cout << "Tapi tanpa dugaan " << name << " air itu begitu cepat menuju dirinya dan....\n";
        cout << "Benar " << name<< " terbawa arus dan membuatnya terhantam kesana-kemari\n";
        cout << name<< " melihat ada tiang yang tinggi dan niatnya adalah bertahan di tiang tersebut.\n ";
        cout << "Dan saat mendekatinya, Deg... ada aliran listrik. " << name << " tanpa sadar terkena aliran tersebut.\n";
        cout << "Kegelapan. Lalu... " << name << " tidak sadar.\n";
    }

    
    pauseLine();

    clearScreen();
    cout << "\n--- SCENE A: DI SEKOLAH (KEBANGKITAN) ---\n";

// Inisialisasi array global team
team[0] = Character(name, "", "");       
team[1] = Character("Astraella", "", "");    
team[2] = Character("Kaelhin", "", "");  
team[3] = Character("Mirayeon", "", "");
team[4] = Character("Eliora", "", ""); 


    int userPick = rand() % NUM_PAPERS;

    team[0].paper = PAPER_LIST[userPick].paper;
    team[0].power = PAPER_LIST[userPick].power;

    cout << name << " membuka mata. Bukan rumah sakit — dia di dalam sebuah sekolah besar yang terasa aneh.\n";
    cout << name << " memutuskan untuk mengelilingi sekolah itu, diawali dari kelaas dimana dia terbangun.\n";
    cout << "Terlihat ada anak dengan surai biru sedang duduk sebelah jendela dia tidak bergerak sama sekali.\n";
    cout << "Apa yang kamu putuskan?\n";
    cout << "\n>1.Mendatanginya. \n>2.Pergi keluar kelas\n";
    
    int keputusanIdx = chooseIndex(2); 
    system("cls");
    if (keputusanIdx == 0) 
    {
        cout << "'Hai?'-"<< name << "\n";
        cout << "<tidak ada jawaban>\n";
        cout << "'halo?'-" << name << "\n";
        cout << "Orang itu pun menoleh dan terlihat sepertinya dia baru saja bangun tidur?\n";
        cout << "'Ada apa?'-" << name << "\n";
        cout << "'Maaf menggangu, cuma mau tanya ini dimana?'-" << name << "\n";
        cout << "'Oh.. kamu orang baru ya disini?'-???\n";
        cout << "'Hah?'(jawab)" << name<< endl;
        cout << "'Gak jadi, tapi intinya kita sekarang lagi di sebuah sekolah bernama Eternis Arcane Academy\n'";
        cout << "'hah?'-" << name << endl;
        cout << "'Intinya kita tinggal disini selamanya maybe?'-???\n";
        cout << "'Oh trus kita semalannya terjebak disini?'-" << name<< endl;
        cout << "<tidak ada jawaban>\n";
        cout << "'Oh iya kalau boleh tau mana mu siapa?'-" << name << endl;
        cout << "'nama ku Astraella salam kenal, kalo kamu?'-Astraella\n";
        cout << "'owh nama aku " << name << "salken juga'-"<< name << "\n";
        cout << "'yaudah aku mau pergi dulu'-" << name << endl;
        cout << "'Wait aku ikut'-Astraella\n";
        cout << "Kalian pun pergi menjelajahi sekolah itu\n";
    }
    else {
        cout << "Kamu pun meninggalkan orang itu lalu menuju lorong kelas.\n";
    }
    cout << "Dan di tengah perjalanan ada pemberitahuan bahwa seluruh orang yang berada di sekolah tersebut harus segera berkumpul diaula\n";
    cout << name << " lalu berjalan menuju aula\n";
    cout << name << " bertemu orang lain. Di sana terlihat ada 5 orang termasuk " << name << "\n";
    cout << "Di depan mereka ada 5 kotak bertuliskan: \"PILIH!\"\n";

    pauseLine();
	system("cls");
    cout << "\n\n\nTiba-tiba, Kotak-kotak itu bersinar dan kertasnya terbagi secara acak!\n";
    cout << name << " mendapatkan kertas: " << team[0].paper
              << " -> KEKUATAN: " << team[0].power << "\n";

    vector<int> availableIndices;

    for (int k = 0; k < NUM_PAPERS; ++k) {
        if (k != userPick) {
            availableIndices.push_back(k);
        }
    }

    cout << "\n4 rekanmu mendapatkan sisa kertas yang ada secara acak:\n";
    random_shuffle(availableIndices.begin(), availableIndices.end()); 

    for (int i = 1; i < NUM_PAPERS; ++i) {\
        int npcIndex = availableIndices[i - 1];

        team[i].paper = PAPER_LIST[npcIndex].paper;
        team[i].power = PAPER_LIST[npcIndex].power;

        cout << team[i].name << " mendapatkan: " << team[i].paper
              << " -> KEKUATAN: " << team[i].power << "\n";
    }

    Character* astraella = &team[1]; 
    Character* kaelhin = &team[2];
    
    cout << "\nSudah 5 bulan berlalu, sungguh waktu begitu cepat.\n";
    cout << "Dan saat pulang sekolah" << name << " ingin pergi ke perpus.\n";
    cout << "'Mau kemana ?'-Mirayeon\n";
    cout << "'Ke perpus.'-" << name << "\n";
    cout << "'jangan lama-lama udah jam 5.53pm'-Mirayeon\n";
    cout << "'Iya iya'-" << name << "\n";
    cout << name << " pun menuju perpustakaan dengan ditemani oleh matahari yang sebentar lagi akan tertidur\n";
    pauseLine();
    book ();
    cout << "\n\n\nSaat diperpustakaan " << name << " menemukan sebuah buku berjudul 'Fortune Teller's' tanpa pikir panjang " << name << "ambil buku itu\n";
    cout << "Yaa.. karena dari sampulnya itu menarik seperti buku kuno dan dari judulnya juga menarik.\n";
    cout << "Setelah itu " << name << " pun kembali ke dormnnya.\n";
    cout << "Dan menyimpan buku itu di rak buku miliknya.\n";
    pauseLine();

    
    clearScreen();
    cout << "\n--- Pertemuan tidak terduga ---\n";
    
    if (astraella && kaelhin) {
        cout << astraella->name << " (" << astraella->power << ") & "
             << kaelhin->name << " (" << kaelhin->power << ") pergi ke gunung untuk mencari bahan latihan.\n";
        cout << "Di puncak, mereka menemukan bekas ritual: tanduk rusa hitam.\n";
        cout << "Muncul sosok: The Antlered King. Ia memancarkan gelap yang menyerap memori.\n";
        cout << astraella->name << " & " << kaelhin->name << " pingsan. Ketika sadar, ingatan tentang sekolah dan teman lenyap.\n";

        astraella->memory_loss = true;
        kaelhin->memory_loss = true;
    } else {
        cout << "Kesalahan internal: Karakter Astraella atau Kaelhin tidak ditemukan.\n";
    }

    pauseLine();

    clearScreen(); 
    cout << "\n--- RAHASIA DI PERPUSTAKAAN ---\n";
    cout << "Beberapa hari kemudian, " << name << " dan mirayeon sedang berjalan menuju kantin, tiba-tiba.\n";
    cout << "'kamu ngerasa itu juga, kan?' tanya Mirayeon tiba-tiba.\n";
    cout << ">1 [yes] \n>2 [no]:";
    cin >> perasaan;
    if (perasaan == 0){
    	cout << name << " mengangguk pelan. 'Iya… dari tadi kayak ada yang manggil.'\n";
	} else {
		cout << "Gak aku gak ngerasa apapun?\n";
		cout << "'Hadeh, aku ngerasa ada yang aneh' jawab Mirayeon\n";
	}
    cout << "Mirayeon dan " << name << " menyusuri rak-rak buku besar yang menjulang\n";
    cout << "tiba-tiba \nMirayeon berhenti. Ekspresinya berubah.\n";
    cout << "'Ada gema… tapi aneh. Dia bergerak.'- Mirayeon\n";
    cout << "Ia memejamkan mata sejenak, mendengarkan frekuensi yang hanya dirinya yang bisa tangkap.\n";
    cout << "dan arah nya menuju...\n";
    cout << "Dorm mereka??. Lebih tepatnya kamar " << name << endl;
    cout << "Mirayeon mendekati salah satu rak buku " << name << " dan mengambil salah satu buku yaitu.\n";
    cout << "'Fortune Teller's' dan tanpa pikkir panjang Mirayeon pun membuka semua halaman yang ada dan menemukan ada salah satu.\n";
    cout << "Halaman sobek, dan di halaman itu memuat nama: 'Antlered King' dan catatan:\n";
    cout << "\"He who collects totems shall erase the road home.\"\n";

    if (astraella && kaelhin) {
        cout << "Membaca nama itu, kilasan memori gunung kembali pada " << astraella->name << " & " << kaelhin->name << ".\n";

        astraella->memory_loss = false;
        kaelhin->memory_loss = false;
    } else {
        cout << "Tidak ada karakter yang perlu memulihkan memori saat ini.\n";
    }
	cout << "'Aku ingat semuanya'-Astraella\n";
	cout <<"Astraella pun menceritakan semuanya kepada teman-temannya\n";
	cout << "Dan mereka semua memutuskan:\n>1) Mencari tahu lebih lanjut tentang Antlered King. \n>2) Lebih baik melupakanya saja.\n";
	cout << ">";
	cin >> pilihan;
	
	if (pilihan == 1){ 
		mencari();
	} else {
		lupakan();
	}
    pauseLine();
 return 0;
}

void bunny(){
	system ("cls");
	cout << "                      /|      __\n";
	cout << "*             +      / |   ,-~ /             +\n";
	cout << "     .              Y :|  //  /                .         *\n";
	cout << "         .          | jj /( .^     *\n";
	cout << "               *    >-''~'-v''              .        *        .\n";
	cout << "*                  /       Y\n";
	cout << "   .     .        jo  o    |     .            +\n";
	cout << "                 ( ~T~     j                     +     .\n";
	cout << "      +           >._-' _./         +\n";
	cout << "               /| ;-''~ _  l\n";
	cout << "  .           / l/ ,-''    \     +\n";
	cout << "              \//\/      .- \\n";
	cout << "       +       Y        /    Y\n";
	cout << "       +       Y        /    Y\n";
	cout << "               l       I     !\n";
	cout << "              ('' ~----( ~   Y.  )\n";
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	string loading = "	-	+	x	+	-";

    for (int i = 0; i < loading.length(); i++) {
        cout << loading[i] << flush;
        Sleep(100); 
    }
    cout << endl;

    pauseLine();

    clearScreen();
	
}
void ending (){
	cout << "=== STATUS AKHIR TIM ===\n";
    for (size_t i = 0; i < NUM_PAPERS; ++i) {
        cout << "- " << team[i].name << " | Kertas: " << team[i].paper << " | Kekuatan: " << team[i].power << "\n";
    }

    cout << "\n--- CERITA SELESAI ---\n";
    pauseLine(); 
    clearScreen(); 

}
void lupakan(){
	bunny();
	cout << "______________________\n";
	cout << "___FORGOTTEN ECHOES___\n";
	cout << "Kalian semua memutuskan untuk melupakan kejadian itu dan menjalani hidup dengan tenang.\n";
	cout << "Pagi itu, seluruh kejadian di Eternis Arcane Academy memudar seperti mimpi yang larut bersama kabut. Tidak ada retakan cahaya, tidak ada suara tanduk, tidak ada portal.\n";
	cout << "Hanya kosong.\n";
	cout << "Dan ketenangan yang aneh.\n";
	cout << "Kaelhin adalah yang pertama bangun di asrama, menatap langit-langit yang terasa terlalu bersih, terlalu putih—seolah tak pernah dilewati bayangan Antlered King\n";
	cout << name << ", Kaelhin, Mirayeon, dan Astraella bangun tak lama kemudian. Mereka saling memandang lama seolah mereka tahu bahwa ada sesuatu yang hilang, namun tidak tahu apa\n";
	cout << "Hari itu mereka tetap datang ke kelas. Tidak ada yang berubah.Eternis Arcane Academy tampak seperti sekolah biasa—tanpa misteri, tanpa bahaya, tanpa rahasia.\n";
	cout << "Mereka menjalani hari-hari seperti biasa. \nTertawa. Belajar. Bercanda.\n";
	cout << "Yang tersisa hanya echo samar di dada mereka. Hangat, namun tidak memiliki wajah.\n";
	cout << "Dan kehidupan terus berlanjut… \nseperti tidak pernah terjadi apa-apa.\n";
	ending ();
}
void mencari(){
	cout << "_______________________________\n";
	cout << "---SEEKERS OF THE LOST TRUTH---\n\n";
	cout << "Mereka semua memutuskan untuk mencari tahu lebih lanjut akan tetapi karena hari sudah malam jadi mereka semua memutuskan untuk tidur terlebih dahulu\n";
	cout << "Setelah menemukan halaman sobek tentang Antlered King, Astraella dan Mirayeon tidak bisa tidur malam itu.\n";
	cout << "Kata-kata misterius itu terus terngiang dalam benak mereka:\n";
	cout << "He who collects totems… shall erase the road home.\n";
	cout << "Pagi itu, mereka mengumpulkan semua anggota tim: Eliora, Kaelhin, Mirayeon, "<< name << ", dan Astraella.\n";
	cout << "Eliora duduk sambil memeluk bantal, wajahnya pucat.\n";
	cout << "“Jadi… yang kalian temukan itu beneran?” tanyanya pelan.\n";
	cout << "Mirayeon mengangguk. “Buku itu kayak… memanggil aku. Dan pas aku buka halaman sobek itu… tubuhku langsung dingin.”\n";
	cout << "'Aku udah coba nanya ke salah satu senior, tentang jalan keluar, dan dia langsung berubah sikap. Seolah itu topik terlarang.' ucap "<< name << endl;
	cout << "Astraella akhirnya bicara, suaranya getar.\n";
	cout << "'…kalian percaya nggak kalau kita… mungkin bukan benar-benar ‘datang’ ke sekolah ini dengan cara normal?'\n";
	cout << "Semua terdiam.\n";
	wis();
	cout << "\n--- Penemuan Simbol Portal ---\n";
    cout << "Kaelhin: Aku nemu tanda aneh di ruang bawah tanah. Kayaknya itu simbol portal mirip yang aku pernah lihat di halaman sobek itu.\n";

    int pilihanAwal;
    cout << "1. Berdiri dan Bertekad: 'Kalau gitu kita harus ke sana.'\n";
    cout << "2. Mengangguk setuju: 'Aku setuju, kita harus lihat.'\n";
    cout << "Pilih (1 atau 2): ";
    system ("cls");
    while (!(cin >> pilihanAwal) || (pilihanAwal != 1 && pilihanAwal != 2)) {
        cout << "Input tidak valid. Pilih 1 atau 2: ";
        cin.clear();
    }
    
    if (pilihanAwal == 1) {
        cout << name << ": Kalau gitu kita harus ke sana.\n";
    } else {
        cout << name << ": Aku setuju, kita harus lihat.\n";
    }


    cout << "Eliora: Tapi itu area yang dilarang... kalau ketahuan...\n";
    cout << "Mirayeon: Justru itu. Mereka ngelarang karena ada sesuatu yang disembunyiin.\n";

    pauseLine();

    cout << "\n--- Pintu Besi dan Ruangan Lukisan ---\n";
    
    int pilihanPerasaan;
    cout << "\n--Reaksi Anda saat berjalan di koridor gelap:--\n";
    cout << "1. Berbisik: 'Perasaan gue nggak enak banget.'\n";
    cout << "2. Diam, tapi menggeleng ngeri.\n";
    cout << "Pilih (1 atau 2): ";
    system ("cls");
    while (!(cin >> pilihanPerasaan) || (pilihanPerasaan != 1 && pilihanPerasaan != 2)) {
        cout << "Input tidak valid. Pilih 1 atau 2: ";
        cin.clear();
    }

    if (pilihanPerasaan == 1) {
        cout << name << ": Perasaan gue nggak enak banget.\n";
    } else {
        cout << name << " (Bergumam): Sunyi sekali...\n";
    }

    
    cout << "Astraella (Menyentuh pintu besi): Dingin banget. Kayak… bukan logam normal.\n";
    cout << "Pintu terbuka... Ruangan penuh lukisan siswa tanpa mata.\n";
    cout << "Mirayeon: Ini sihir. Mereka… menghapus sesuatu.\n";

    int pilihanLukisan;
    cout << "\n**Pertanyaan Anda tentang lukisan:**\n";
    cout << "1. 'Menghapus apa? Kenangan? Identitas? Jalan pulang?'\n";
    cout << "2. 'Apa yang terjadi pada siswa-siswa ini? Apakah mereka sudah dilupakan?'\n";
    cout << "Pilih (1 atau 2): ";
    system ("cls");
    while (!(cin >> pilihanLukisan) || (pilihanLukisan != 1 && pilihanLukisan != 2)) {
        cout << "Input tidak valid. Pilih 1 atau 2: ";
        cin.clear();
    }

    if (pilihanLukisan == 1) {
        cout << name << " (Menggeleng ngeri): Menghapus apa? Kenangan? Identitas? Jalan pulang?\n";
    } else {
        cout << name << " (Ngeri): Apa yang terjadi pada siswa-siswa ini? Apakah mereka sudah dilupakan?\n";
    }
    
    pauseLine();

    cout << "\n*** Totem Raksasa & Antlered King ***\n";
    cout << "Mereka menemukan lima patung totem raksasa dengan celah kotak kecil.\n";
    cout << "Kaelhin: Ini… bentuknya sama kayak… Antlered King.\n";
    cout << "Astraella: Jadi ‘he who collects totems’… itu dia?\n";

    int pilihanTotem;
    cout << "\n**Pikiran ngeri Anda tentang Totem:**\n";
    cout << "1. 'Kalau dia ngumpulin semua totem ini… jalan pulang kita bakal dihapus?'\n";
    cout << "2. 'Apakah ini yang digunakan untuk menjebak kita? Kita harus menghancurkannya.'\n";
    cout << "Pilih (1 atau 2): ";
    system ("cls");
    while (!(cin >> pilihanTotem) || (pilihanTotem != 1 && pilihanTotem != 2)) {
        cout << "Input tidak valid. Pilih 1 atau 2: ";
        cin.clear();
    }

    if (pilihanTotem == 1) {
        cout << name << " (Menelan ludah): Kalau dia ngumpulin semua totem ini… jalan pulang kita bakal dihapus?\n";
    } else {
        cout << name << " (Cemas): Apakah ini yang digunakan untuk menjebak kita? Kita harus menghancurkannya.\n";
    }
    

    cout << "Mirayeon: Bukan cuma kita… mungkin semua siswa. Atau pulau ini sendiri.\n";
    pauseLine();

    cout << "\n*** Daftar 'Chosen Subjects' ***\n";
    cout << "Meja kayu tua dan tumpukan catatan mengungkap nama mereka dalam daftar 'Chosen Subjects'.\n";
    cout << "Kaelhin (Mengepalkan tangan): Ini bukan sekolah… ini eksperimen.\n";
    cout << "Eliora (Jatuh berlutut): Kita cuma… umpan buat Antlered King?\n";

    int pilihanAkhir;
    cout << "\n**Keputusan Anda setelah tahu kebenasan (menggantikan 'Ayo kabur'):**\n";
    cout << "1. 'Ayo kabur.' (Menarik napas panjang, bersiap)\n";
    cout << "2. 'Kita tidak punya waktu lagi. Kita pergi sekarang!'\n";
    cout << "Pilih (1 atau 2): ";
    
    while (!(cin >> pilihanAkhir) || (pilihanAkhir != 1 && pilihanAkhir != 2)) {
        cout << "Input tidak valid. Pilih 1 atau 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pilihanAkhir == 1) {
        cout << name << " (Menarik napas panjang): Ayo kabur.\n";
    } else {
        cout << name << " (Tegas): Kita tidak punya waktu lagi. Kita pergi sekarang!\n";
    }

    cout << "Astraella: Kita harus cari portal itu. Apapun caranya.\n";
    cout << "Eliora: Apapun yang terjadi… kita tetap bareng, kan?\n";
    cout << "Astraella: Selalu.\n";

    cout << "\n========================================\n";
    cout << "  FINALE: Mereka meninggalkan ruang rahasia. Perjalanan untuk melanggar aturan sekolah, menuju portal, menuju takdir yang sepenuhnya mereka pilih sendiri, telah dimulai.\n";
    cout << "========================================\n";
    wis();
    ending(); 
}

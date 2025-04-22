typedef char infotype[100];

typedef struct tKota *address_kota;
typedef struct tPenduduk *address_penduduk;

typedef struct tKota
{
  infotype info;
  address_kota next_kota;
  address_penduduk next_penduduk;
} Kota;

typedef struct tPenduduk
{
  infotype info;
  address_penduduk next;
} Penduduk;

// insert first
void insert_kota(address_kota *head, infotype data);

// insert first penduduk berdasarkan kota
void insert_penduduk(address_kota *head, infotype kota, infotype data);

// delete kota
void delete_kota(address_kota *head, infotype kota);

// delete penduduk berdasarkan kota
void delete_penduduk(address_kota *head, infotype kota, infotype penduduk);

// tampil semua kota
void tampil_kota(address_kota head);

// tampil penduduk dari kota
void tampil_penduduk(address_kota head, infotype kota);

// cari dan kembalikan kota
address_kota cari_kota(address_kota head, infotype kota);
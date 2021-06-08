# UAC-Bypass-OpenPS

Eventvwr.exe bir High Integrity process’i olarak mmc.exe’yi başlatmak için hem HKCU hem HKCR’de sorgu yaptığını bilmeliyiz. Mmc.exe çalıştıktan sonra Event Viewer’ın açılmasına neden olan eventvwr.msc dosyasını açar. Buradan hareketle eventvwr.exe için HKCR konumu yerine HKCU konumunu sorgulamak için kayıt defteri oluşturulabilir.

Oluşturulan mmc.exe'nin yerine powershell.exe'yi koyduğumuzda yüksek ayrıcalıklı olarak powershell.exe'yi çalıştırıyoruz.

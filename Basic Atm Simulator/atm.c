#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sabit kullanıcı bilgileri
#define USERNAME "asli"
#define PASSWORD "1234"

int main() {
    char username[20], password[20];
    int balance = 1000; // Başlangıç bakiyesi
    int choice, amount;

    printf("ATM Sistemine Hoş Geldiniz!\n");
    
    // Kullanıcı girişi
    printf("Kullanıcı adını giriniz: ");
    scanf("%s", username);
    printf("Şifreyi giriniz: ");
    scanf("%s", password);

    // Giriş kontrolü
    if (strcmp(username, USERNAME) != 0 || strcmp(password, PASSWORD) != 0) {
        printf("Kullanıcı adı veya şifre hatalı!\n");
        return 0;
    }

    do {
        // Menü
        printf("\n---- ATM Menüsü ----\n");
        printf("1. Bakiye Görüntüle\n");
        printf("2. Para Yatır\n");
        printf("3. Para Çek\n");
        printf("4. Çıkış\n");
        printf("Seçiminizi giriniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Mevcut bakiyeniz: %d TL\n", balance);
                break;
            case 2:
                printf("Yatırmak istediğiniz tutarı giriniz: ");
                scanf("%d", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("%d TL başarıyla yatırıldı. Yeni bakiyeniz: %d TL\n", amount, balance);
                } else {
                    printf("Geçersiz tutar!\n");
                }
                break;
            case 3:
                printf("Çekmek istediğiniz tutarı giriniz: ");
                scanf("%d", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("%d TL başarıyla çekildi. Kalan bakiyeniz: %d TL\n", amount, balance);
                } else {
                    printf("Geçersiz işlem! Yetersiz bakiye veya geçersiz tutar.\n");
                }
                break;
            case 4:
                printf("Çıkış yapılıyor...\n");
                break;
            default:
                printf("Geçersiz seçim!\n");
        }

    } while (choice != 4);

    printf("ATM sistemini kullandığınız için teşekkürler.\n");
    return 0;
}

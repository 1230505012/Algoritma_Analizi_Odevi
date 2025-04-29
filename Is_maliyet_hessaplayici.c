#include <stdio.h>
#include <limits.h>

#define MAKS_IS 100
#define MAKS_MAKINE 100

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int is_sayisi, makine_sayisi;
    int is_suresi[MAKS_IS][MAKS_MAKINE];
    int gecis_maliyeti[MAKS_MAKINE][MAKS_MAKINE];
    int dp[MAKS_IS][MAKS_MAKINE];
    int i, j, k;

    printf("Is sayisini ve makine sayisini giriniz: ");
    scanf("%d %d", &is_sayisi, &makine_sayisi);

    printf("\nHer is icin makinelere gore isleme surelerini giriniz:\n");
    for (i = 0; i < is_sayisi; i++) {
        printf("Is %d: ", i + 1);
        for (j = 0; j < makine_sayisi; j++) {
            scanf("%d", &is_suresi[i][j]);// her iþ için her makinenin süresi
        }
    }

    printf("\nMakineden makineye gecis maliyetlerini giriniz:\n");
    for (i = 0; i < makine_sayisi; i++) {
        printf("Makine %d: ", i + 1);
        for (j = 0; j < makine_sayisi; j++) {
            scanf("%d", &gecis_maliyeti[i][j]);
        }
    }
// Ýlk iþin süreleri doðrudan dp tablosuna yazýlýr
    for (j = 0; j < makine_sayisi; j++) {
        dp[0][j] = is_suresi[0][j];
    }
// Diðer iþler için en düþük geçiþli yol hesaplanýr
    for (i = 1; i < is_sayisi; i++) {
        for (j = 0; j < makine_sayisi; j++) {
            dp[i][j] = INT_MAX;
            for (k = 0; k < makine_sayisi; k++) {
                int toplam_sure = dp[i - 1][k] + gecis_maliyeti[k][j] + is_suresi[i][j];
                dp[i][j] = min(dp[i][j], toplam_sure);
            }
        }
    }

    int minimum_sure = INT_MAX;
    for (j = 0; j < makine_sayisi; j++) {
        if (dp[is_sayisi - 1][j] < minimum_sure) {
            minimum_sure = dp[is_sayisi - 1][j];
        }
    }

    printf("\nMinimum toplam is tamamlama suresi: %d\n", minimum_sure);
    return 0;
}


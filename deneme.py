import matplotlib.pyplot as plt
import random

# --- Dinamik Programlama (DP) Çözümü Fonksiyonu ---
def lcs_dp_simulation(X, Y):
    m = len(X)
    n = len(Y)
    
    # DP tablosu oluşturma
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    primitive_ops = 0 # Temel işlem sayacı: Her hücre doldurulduğunda artırılacak
    
    # DP tablosunu doldurma döngüleri
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            primitive_ops += 1 # Her bir hücre için bir işlem sayıyoruz
            
            # Karakterler aynı mı farklı mı kontrolü
            if X[i-1] == Y[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                
    return dp[m][n], primitive_ops # LCS uzunluğu ve toplam işlem sayısı

# --- Yardımcı Fonksiyon: Rastgele DNA Dizisi Oluşturma ---
def generate_random_dna(length):
    return ''.join(random.choice('ACGT') for _ in range(length))

# --- Simülasyon Ayarları ---
# Test etmek istediğimiz girdi boyutları.
# Genellikle iki diziyi eşit uzunlukta kabul ederiz (n = m)
input_sizes = range(1, 151) # 1'den 150'ye kadar olan uzunlukları test edelim
dp_ops_counts = [] # Her boyut için işlem sayılarını burada saklayacağız

# --- Simülasyon Çalıştırma ---
print("Simülasyon Başlıyor...")
for size in input_sizes:
    # Belirtilen boyutta rastgele iki DNA dizisi oluştur
    X_dna = generate_random_dna(size)
    Y_dna = generate_random_dna(size)
    
    # LCS DP fonksiyonunu çağır ve işlem sayısını al
    _, ops_count = lcs_dp_simulation(X_dna, Y_dna)
    dp_ops_counts.append(ops_count)
    
    # İlerleme göstermek için her 10 adımda bir çıktı verelim
    if size % 10 == 0:
        print(f"Boyut {size} için hesaplama tamamlandı.")

print("Simülasyon Tamamlandı.")

# --- Bulguları Çizme (Grafik) ---
plt.figure(figsize=(10, 6)) # Grafiğin boyutunu ayarla
plt.plot(input_sizes, dp_ops_counts, label='Dinamik Programlama (O(n*m))', marker='o', markersize=3, linestyle='-')

plt.xlabel('Girdi Boyutu (n = m)')
plt.ylabel('Temel İşlem Sayısı')
plt.title('Dinamik Programlama LCS Algoritmasının Büyüme Oranı')
plt.legend()
plt.grid(True) # Izgara çizgilerini göster
plt.show() # Grafiği ekranda göster

# --- Bulguları Raporlama (Tablo) ---
print("\n--- Simülasyon Sonuçları (DP) ---")
print("Girdi Boyutu (n) | İşlem Sayısı (n*n ile Orantılı)")
print("-------------------------------------------------")
# İlk 5 ve son 5 sonucu yazdıralım
for i in range(min(5, len(input_sizes))):
    size = input_sizes[i]
    print(f"{size:<17} | {dp_ops_counts[i]:<30}")
if len(input_sizes) > 10: # Eğer dizi yeterince uzunsa "..." göster
    print("...")
for i in range(max(0, len(input_sizes) - 5), len(input_sizes)):
    size = input_sizes[i]
    print(f"{size:<17} | {dp_ops_counts[i]:<30}")

## 📖 Descriere  
Acest proiect implementează o **barieră automată** controlată de un **servomotor**, care se ridică și coboară în funcție de datele furnizate de un **senzor de proximitate**. 🚗💨  

🔹 **Scopul proiectului** este de a oferi o soluție **simplă, accesibilă și eficientă** pentru gestionarea accesului în diverse locații, precum parcări sau spații private. 🏢  

---

## 🎯 **Obiective**  
✅ Sincronizarea mișcării servomotorului cu LED-urile de semnalizare.  
✅ Implementarea unui sistem autonom bazat pe un senzor ultrasonic.  
✅ Crearea unei soluții educative pentru învățarea principiilor Arduino.  

---

## 🛠 **Componente hardware utilizate**  
- 🔹 **Arduino Uno** – pentru controlul logicii sistemului.  
- 🔹 **Senzor ultrasonic HC-SR04** – pentru detectarea obiectelor.  
- 🔹 **Servomotor SG90** – pentru mișcarea barierei.  
- 🔹 **LED-uri** (roșu 🟥, galben 🟨, verde 🟩) pentru semnalizare.  
- 🔹 **Breadboard și fire de conexiune** pentru interconectarea componentelor.  

---

## ⚙️ **Funcționare**  
📡 Senzorul **HC-SR04** măsoară distanța față de obstacol.  
🔴 **LED roșu aprins** – bariera este coborâtă.  
🟡 **LED galben aprins** – bariera este în mișcare.  
🟢 **LED verde aprins** – bariera este ridicată.  
🔄 După câteva secunde, bariera revine la poziția inițială.  

---

## 📝 **Algoritmul de funcționare**  
1️⃣ **Măsurarea distanței** cu senzorul ultrasonic.  
2️⃣ **Dacă un obiect este detectat (sub 20 cm):**  
   - LED-ul **roșu se stinge**, LED-ul **galben se aprinde**.  
   - Bariera **se ridică treptat** cu servomotorul.  
   - LED-ul **galben se stinge**, LED-ul **verde se aprinde**.  
3️⃣ **După 5 secunde:**  
   - LED-ul **verde se stinge**, LED-ul **galben se reaprinde**.  
   - Bariera **coboară treptat**.  
   - LED-ul **galben se stinge**, LED-ul **roșu se reaprinde**.  

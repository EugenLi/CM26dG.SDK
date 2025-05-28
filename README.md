# CM26dG.SDK – C# Bibliothek für Konica Minolta CM-26dG

Diese .NET Framework 4.8-Klassenbibliothek dient zur Kommunikation mit dem Spektralfotometer **Konica Minolta CM-26dG** über das offizielle MISDK (Color Management Instrument SDK).

---

## 🔧 Voraussetzungen

- **Windows 10 oder höher**
- **.NET Framework 4.8**
- **CMMISDK.NET.dll** aus dem offiziellen SDK von Konica Minolta
- Gerät per **USB oder seriell verbunden** (COM-Port)

---

## 📦 Installation

1. Füge `CMMISDK.NET.dll` als **Verweis** zum Projekt hinzu.
2. Stelle sicher, dass auch `CMMISDK_x64.dll` oder `CMMISDK.dll` im Ausgabeverzeichnis liegt.
3. Zielplattform: **x86 oder x64** je nach Gerät und Treiber.

---

## 📚 Projektstruktur

```text
CM26dG.SDK/
├── Interfaces/
│   └── IColorMeter.cs           // Schnittstelle zur Gerätekommunikation
├── Models/
│   └── MeasurementResult.cs     // Rückgabemodell für Messergebnisse
├── Services/
│   └── ColorMeterService.cs     // Hauptimplementierung
├── README.md
```

---

## ✅ Unterstützte Funktionen

- Geräteliste ermitteln (`FindDevicesAsync`)
- Verbindung herstellen zu einem COM-Port
- Gerät konfigurieren für SCI, SCE und Glanzmessung
- Messung auslösen und Spektrum + Glanzwert lesen
- Verbindung trennen

---

## 🚀 Beispiel

```csharp
IColorMeter meter = new ColorMeterService();

await meter.ConnectAsync();                       // COM-Port automatisch wählen
await meter.ConfigureMeasurementAsync();          // SCI, SCE, Glanz konfigurieren

var result = await meter.MeasureAsync();          // Messung durchführen

Console.WriteLine("Glanz: " + result.Gloss);
Console.WriteLine("SCI [0]: " + result.SpectrumSCI[0]);

await meter.DisconnectAsync();                    // Verbindung schließen
```

---

## ⚠️ Fehlerbehandlung

Alle SDK-Aufrufe werden geprüft und werfen bei Fehlern eine aussagekräftige `InvalidOperationException` mit dem Fehlercode und SDK-Meldung.

---


---

## 🧩 USB-Treiberinstallation (Windows)

Das Gerät **Konica Minolta CM-26dG** benötigt einen USB-Treiber, der mit einer `.INF`-Datei installiert wird.

### 🔹 Automatische Installation

1. Gerät per USB anschließen und einschalten.
2. Windows versucht automatisch, den Treiber zu installieren.
3. Wird ein COM-Port erstellt: ✅ Fertig.

### 🔹 Manuelle Installation

Falls Windows den Treiber nicht automatisch installiert:

1. Öffne den **Geräte-Manager**.
2. Rechtsklick auf das Gerät unter **[Andere Geräte] → [Measuring Instruments]** → **[Treibersoftware aktualisieren]**.
3. Wähle: **„Auf dem Computer nach Treibersoftware suchen“**.
4. Dann: **„Aus einer Liste von Gerätetreibern auf dem Computer auswählen“**.
5. Kategorie: **Ports (COM & LPT)** → **[Weiter]**.
6. Klicke auf **[Datenträger] → [Durchsuchen]**.
7. Wähle die Datei:  
   `cm-misdk_verXXXrX/driver/KMMIUSB.INF`
8. Bestätige mit **[OK]** und folge dem Assistenten.

📌 Nach erfolgreicher Installation wird das Gerät unter **COM-Ports** sichtbar und kann mit der Bibliothek verwendet werden.


## 📄 Lizenz

Dieses Projekt ist intern oder privat nutzbar, es basiert auf dem proprietären SDK von Konica Minolta. Bitte beachte die Lizenzbedingungen des Herstellers.

---

## 🛠 Autor

Eugen Lieder

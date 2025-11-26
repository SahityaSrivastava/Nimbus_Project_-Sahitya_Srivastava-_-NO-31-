#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== DEVICE STRUCTURE =====
typedef struct {
    int id;
    char name[50];
    char type[50];
    int status;             // 0 = OFF, 1 = ON
    float power_rating;     // Watts
    float current_power;
    float energy_usage;     // kWh
} Device;

// ===== GLOBAL VARIABLES =====
Device devices[2];
int device_count = 0;

// ===== FUNCTION PROTOTYPES =====
void initialize_system();
void add_device(int id, char *name, char *type, float power_rating);
void turn_on_device(int device_id);
void turn_off_device(int device_id);
void show_all_devices();
void energy_report();
void show_menu();

// ===== INITIALIZE SYSTEM =====
void initialize_system() {
    printf("\n========== Initializing Smart Home ==========\n");
    
    // Add Smart Plug 1: Laptop Charger
    add_device(1, "Laptop Charger", "Smart Plug", 65.0);
    
    // Add Smart Plug 2: Kitchen Appliance
    add_device(2, "Kitchen Appliance", "Smart Plug", 1500.0);
    
    printf("✓ System Ready!\n");
    printf("✓ 2 Smart Plugs Added\n\n");
}

// ===== ADD DEVICE =====
void add_device(int id, char *name, char *type, float power_rating) {
    if (device_count >= 2) {
        printf("Cannot add more devices!\n");
        return;
    }
    
    devices[device_count].id = id;
    strcpy(devices[device_count].name, name);
    strcpy(devices[device_count].type, type);
    devices[device_count].status = 0;
    devices[device_count].power_rating = power_rating;
    devices[device_count].current_power = 0;
    devices[device_count].energy_usage = 0;
    
    device_count++;
}

// ===== TURN ON DEVICE =====
void turn_on_device(int device_id) {
    if (device_id < 1 || device_id > 2) {
        printf("Invalid device ID!\n");
        return;
    }
    
    Device *dev = &devices[device_id - 1];
    
    if (dev->status == 1) {
        printf("%s is already ON!\n\n", dev->name);
        return;
    }
    
    dev->status = 1;
    dev->current_power = dev->power_rating;
    dev->energy_usage += (dev->power_rating / 1000) * 0.5;
    
    printf("✓ %s turned ON\n", dev->name);
    printf("  Power: %.1f W\n\n", dev->current_power);
}

// ===== TURN OFF DEVICE =====
void turn_off_device(int device_id) {
    if (device_id < 1 || device_id > 2) {
        printf("Invalid device ID!\n");
        return;
    }
    
    Device *dev = &devices[device_id - 1];
    
    if (dev->status == 0) {
        printf("%s is already OFF!\n\n", dev->name);
        return;
    }
    
    dev->status = 0;
    dev->current_power = 0;
    
    printf("✓ %s turned OFF\n\n", dev->name);
}

// ===== SHOW ALL DEVICES =====
void show_all_devices() {
    printf("\n========== All Devices Status ==========\n\n");
    
    for (int i = 0; i < device_count; i++) {
        Device *dev = &devices[i];
        printf("Device %d: %s\n", dev->id, dev->name);
        printf("  Type: %s\n", dev->type);
        printf("  Status: %s\n", dev->status ? "ON ✓" : "OFF ✗");
        printf("  Power Rating: %.1f W\n", dev->power_rating);
        printf("  Current Power: %.1f W\n", dev->current_power);
        printf("  Energy Used: %.3f kWh\n\n", dev->energy_usage);
    }
    
    printf("========================================\n\n");
}

// ===== ENERGY REPORT =====
void energy_report() {
    float total_power = 0;
    float total_energy = 0;
    
    printf("\n========== Energy Report ==========\n\n");
    
    for (int i = 0; i < device_count; i++) {
        total_power += devices[i].current_power;
        total_energy += devices[i].energy_usage;
        
        printf("%s:\n", devices[i].name);
        printf("  Current Power: %.1f W\n", devices[i].current_power);
        printf("  Total Energy Used: %.3f kWh\n\n", devices[i].energy_usage);
    }
    
    printf("--- Total Summary ---\n");
    printf("Total Current Power: %.1f W\n", total_power);
    printf("Total Energy Consumed: %.3f kWh\n", total_energy);
    printf("====================================\n\n");
}

// ===== SHOW MENU =====
void show_menu() {
    printf("\n╔════════════════════════════════════╗\n");
    printf("║   Smart Home Control - 4 Options  ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    printf("1. Turn ON Device\n");
    printf("2. Turn OFF Device\n");
    printf("3. View All Devices\n");
    printf("4. Exit\n\n");
    printf("Choose option (1-4): ");
}

// ===== MAIN PROGRAM =====
int main() {
    int choice, device_id;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║  Smart Home Automation Controller  ║\n");
    printf("║     2 Smart Plugs in C             ║\n");
    printf("╚════════════════════════════════════╝\n");
    
    initialize_system();
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter Device ID (1=Laptop Charger, 2=Kitchen Appliance): ");
                scanf("%d", &device_id);
                turn_on_device(device_id);
                break;
                
            case 2:
                printf("\nEnter Device ID (1=Laptop Charger, 2=Kitchen Appliance): ");
                scanf("%d", &device_id);
                turn_off_device(device_id);
                break;
                
            case 3:
                show_all_devices();
                energy_report();
                break;
                
            case 4:
                printf("\nThank you for using Smart Home Controller!\n");
                printf("Goodbye! 👋\n\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-4.\n\n");
                // Clear input buffer
                while (getchar() != '\n');
        }
    }
    
    return 0;
}

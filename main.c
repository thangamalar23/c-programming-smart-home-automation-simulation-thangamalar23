/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void toggleLight(int rooms, int lights[]);
 void readTemperature(int rooms, int temp[]);
 void detectMotion(int rooms, int motion[]);
 void controlLock(int rooms, int locks[]);
 void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);
 
 int main() {
     int rooms;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
     
     int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
     initializeSystem(rooms, lights, temp, motion, locks);
     
     int choice;
     do {
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status Summary\n6. Exit\nEnter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1: toggleLight(rooms, lights); break;
             case 2: readTemperature(rooms, temp); break;
             case 3: detectMotion(rooms, motion); break;
             case 4: controlLock(rooms, locks); break;
             case 5: analyzeHouseStatus(rooms, lights, temp, motion, locks); break;
             case 6: printf("Exiting...\n"); break;
             default: printf("Invalid choice, try again.\n");
         }
     } while (choice != 6);
     
     return 0;
 }
 
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;  // OFF
         temp[i] = 22;   // Default 22°C
         motion[i] = 0;  // No motion
         locks[i] = 1;    // Locked
     }
     printf("System initialized successfully!\n");
 }
 
 void toggleLight(int rooms, int lights[]) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         lights[room - 1] = !lights[room - 1];
         printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void readTemperature(int rooms, int temp[]) {
     int room;
     printf("Enter room number to check temperature (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Temperature in Room %d: %d°C\n", room, temp[room - 1]);
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void detectMotion(int rooms, int motion[]) {
     int room;
     printf("Enter room number to check motion sensor (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void controlLock(int rooms, int locks[]) {
     int room;
     printf("Enter room number to lock/unlock (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         locks[room - 1] = !locks[room - 1];
         printf("Door in Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
                i + 1, lights[i] ? "ON" : "OFF", temp[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
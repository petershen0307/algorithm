package main

import (
	"fmt"
	"sync"
	"time"
)

func diningOrder(id int, chapsticks []int, wg *sync.WaitGroup, mutex *sync.Mutex) {
	// id[0] use chapstick[0] and chapsticks[len(chapsticks)-1]
	// id        id               (id + max id - 1) % max id
	defer wg.Done()
	fmt.Printf("This is number %v philosopher.\n", id)
	chapstickIndex := (id + len(chapsticks) - 1) % len(chapsticks)
	ate := false
	for !ate {
		mutex.Lock()
		if 0 == chapsticks[id] && 0 == chapsticks[chapstickIndex] {
			chapsticks[id], chapsticks[chapstickIndex] = 1, 1
			time.Sleep(3 * time.Second)
			ate = true
			chapsticks[id], chapsticks[chapstickIndex] = 0, 0
		}
		mutex.Unlock()
	}
	fmt.Printf("philosopher %v finish dinner.\n", id)
}

func main() {
	const PHILOSOPHERS = 5
	chapsticks := make([]int, PHILOSOPHERS, PHILOSOPHERS)
	var wg sync.WaitGroup
	wg.Add(PHILOSOPHERS)
	var mutex sync.Mutex
	for i := 0; i < PHILOSOPHERS; i++ {
		go diningOrder(i, chapsticks, &wg, &mutex)
	}
	wg.Wait()
}

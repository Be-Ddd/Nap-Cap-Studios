I worked in XCode.

For task 1, I filled out code for SLPhotonSet.cpp and its header in simialr fashion to AsteriodSet.
For task 2, I added code in SLGameScene to check if the ship could fire and if the firing key was pressed before calling the function in SLPhotonSet for generating a photon. As the ship's location, angle and velocity were passed in, I created photons based on the info.
For task 3, I did code very similar to Asteroids and transformed the images.
For task 4, adding a sound was easy as I just had to put it in SLGameScene whenever a photon is created.
For task 5, I added code to CollisionController.cpp and its header, in a logic simialr to ship & asteroid collisions. I added code for spawning new asteroids. I then called this function in gamescene to check for these collisions.
For task 6, I added if statements in the update and render function of gamescene. I added a new attribute gameState and changes the ending message and animations accordingly.

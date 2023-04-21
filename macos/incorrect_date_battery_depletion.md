# Incorrect auto date and time on M1 MacBook after battery depletion

- Disable auto date time
- Finder go to folder `/var/db`
- Right click on `./timed`, then on `Get Info`, Allow `read & write` access to everyone
- Finder go to folder `./timed`, delete `com.apple.timed.plist`
- Restart
- Enable auto date time
- Change the permission of `./timed` back to `no access`

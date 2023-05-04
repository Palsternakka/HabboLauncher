![image](https://user-images.githubusercontent.com/41788480/236338825-b81ddb37-277c-40d4-88e2-4d742ba14fc4.png)

# Information

HabboLauncher is a standalone executable that allows the user to launch either the Shockwave or Flash client, that when built is less than 15 MB. It works with [this fork of Havana](https://github.com/JeppsonDev/Havana)

Both the .NET version and C++ version are fully functional, however the C++ version is recommended for distribution as it works best with Wine, tested on MacOS (on Apple Silicon) and Ubuntu

### How it works

Necessary files are extracted to `%AppData%\HabboLauncher%` on launch, including the Shockwave projector and standalone Flash executable

Upon clicking login, a HTTP get request is sent to `.../api/ticket?username=User&password=password`

If the username and password are correct, the following JSON is returned -

```json
{
  "host": "127.0.0.1",
  "site": "http://localhost",
  "musPort": "12322",
  "shockwavePort": "12321",
  "shockwaveDcr": "http://localhost/client/v31/habbo.dcr?",
  "shockwaveVariables": "http://localhost/client/v31/gamedata/external_variables_http.txt?country=uk",
  "shockwaveTexts": "http://localhost/client/v31/gamedata/external_texts.txt?",
  "flashPort": "12323",
  "flashBase": "http://localhost/client/v39/",
  "flashSwf": "http://localhost/client/v39/Habbo.swf?",
  "flashVariables": "http://localhost/client/v39/gamedata/external_variables_exe.txt?",
  "flashTexts": "http://localhost/client/v39/gamedata/external_flash_texts.txt?",
  "ssoTicket": "5dd07f5d-e9d9-4552-aade-1543d6ed1c80"
}
```

If the user chose to launch the Flash client, the standalone Flash executable is launched with the necessary arguments, if the user chose to launch the Shockwave executable, the Shockwave projector is run and reads a file written to the above directory

### Configuring for your hotel 

Find and replace `https://YOUR-HOTEL-HERE` with your hotel's URL

Double-clicking the Habbo logo sets the URL to `http://localhost` for that running instance - a useful debugging feature if testing a local hotel

## Notes

The Shockwave executable can be modified in Director MX 2004 - `project.dir`

### fuse_client.cct

This modified version of `fuse_client.cct` will perform Javascript calls only if `do.javascript.calls=true` is in `external_variables.txt`

## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

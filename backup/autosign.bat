@echo off
color 2f
echo.
echo.
echo.
echo               ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
echo               ▇                                            ▇
echo               ▇--------------------------------------------▇
echo               ▇          ********正在签名********          ▇
echo               ▇--------------------------------------------▇
echo               ▇                                            ▇
echo               ▇             正在加载证书私钥...            ▇
echo               ▇                                            ▇
echo               ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
signtool.exe sign /v /f 证书PFX文件 /p 证书密码 /tr http://timestamp.wosign.com/rfc3161 签名文件 1>signlogs.log
cls
echo.
echo.
echo.
echo               ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
echo               ▇                                            ▇
echo               ▇--------------------------------------------▇
echo               ▇          ********签名完成********          ▇
echo               ▇--------------------------------------------▇
echo               ▇                                            ▇
echo               ▇          查看日志请访问signlogs.log        ▇
echo               ▇                                            ▇
echo               ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇
type signlogs.log
pause
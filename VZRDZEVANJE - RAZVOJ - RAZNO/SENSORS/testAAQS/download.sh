# import textile to "clipboard"
#curl -i -H "Accept: application/xml" -H "Content-Type: application/xml" -X GET -u nkostic:Kosnik00 http://pivka.arso.sigov.si/redmine/projects/aaqs_location_00402_e402_mobilna_postaja_kombi/wiki/Wiki.xml | xclip -selection c
curl -i -H "Accept: application/xml" -H "Content-Type: application/xml" -X GET -u nkostic:Kosnik00 http://pivka.arso.sigov.si/redmine/projects/e4000_test_wiki-testna-postaja/wiki/Wiki.xml > textile.xml

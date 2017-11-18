before_commit: format check_lines

check_lines:
	@for file in $$(find . -name *.cpp); do if [ `cat $$file | wc -l` -gt 200 ]; then echo "$$file have more than 200 lines"; fi; done;

format:
	@find src/* -type f -exec uncrustify -c uncrustify.cfg -l CPP --no-backup -q {} \;
	@find test/*.cpp -type f -exec uncrustify -c uncrustify.cfg -l CPP --no-backup -q {} \;


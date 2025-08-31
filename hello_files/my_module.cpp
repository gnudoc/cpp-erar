module;

#include <string>
#include <filesystem>

export module my_module;

export namespace my_module {

    void bulk_rename(const std::string& path) {
        namespace fs = std::filesystem;

        for(const auto& file: fs::directory_iterator(path)) {
            if(not file.is_regular_file()) continue;

            const auto& file_path = file.path();
            const auto& parent_path = file_path.parent_path();
            const auto& file_name = file_path.stem();
            const auto& ext = file_path.extension();

            const auto new_filename = file_name.string() + "_rocks" + ext.string();
            const auto new_path = parent_path / new_filename;
            fs::rename(file_path, new_path);
        }
    }
}

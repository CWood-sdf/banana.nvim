const std = @import("std");

// Although this function looks imperative, note that its job is to
// declaratively construct a build graph that will be executed by an external
// runner.
pub fn build(b: *std.Build) void {
    // const file = std.fs.cwd().readFileAlloc(std.heap.page_allocator, "src/box.zig", 100000) catch std.heap.page_allocator.alloc(u8, 1) catch return;
    //
    // defer std.heap.page_allocator.free(file);
    //
    // const fileZeroed = std.heap.page_allocator.dupeZ(u8, file) catch return;
    // defer std.heap.page_allocator.free(fileZeroed);
    //
    // var ast = std.zig.Ast.parse(std.heap.page_allocator, fileZeroed, .zig) catch return;
    // defer ast.deinit(std.heap.page_allocator);
    //
    // const rootDecls = ast.rootDecls();
    //
    // for (rootDecls) |decl| {
    //     const node: std.zig.Ast.Node.Data = ast.nodes.items(.data)[decl];
    //     const tag: std.zig.Ast.Node.Tag = ast.nodes.items(.tag)[decl];
    //     if (tag == .fn_decl) {
    //         std.debug.print("{}\n", .{tag});
    //         // std.debug.print("{}\n", .{node});
    //         const protoTag = ast.nodes.items(.tag)[node.lhs];
    //         std.debug.print("{}\n", .{protoTag});
    //         switch (protoTag) {
    //             .fn_proto_simple => {
    //                 var buffer: [1]std.zig.Ast.Node.Index = undefined;
    //                 const proto: std.zig.Ast.full.FnProto = ast.fnProtoSimple(&buffer, node.lhs);
    //                 if (proto.visib_token) |tok| {
    //                     const tp = ast.tokens.items(.tag)[tok];
    //                     std.debug.print("visb token: {}\n", .{tp});
    //                 }
    //                 const tok = proto.visib_token.?;
    //                 std.debug.print("{}\n", .{proto});
    //             },
    //             .fn_proto_multi => {
    //                 std.debug.print("Multi\n", .{});
    //             },
    //             else => unreachable,
    //         }
    //     }
    // }
    // const node: std.zig.Ast.Node.Data = ast.nodes.items(.data)[0];
    // const tag: std.zig.Ast.Node.Tag = ast.nodes.items(.tag)[0];
    // std.debug.print("{}\n", .{tag});
    // std.debug.print("{}\n", .{node});
    // std.debug.assert(tag == .root);
    //
    // std.debug.print("loop\n", .{});
    // for (node.rhs..node.rhs + 1) |i| {
    //     const item: std.zig.Ast.Node.Tag = ast.nodes.items(.tag)[i];
    //     std.debug.print("{}\n", .{item});
    //
    //     const data = ast.nodes.items(.data)[i];
    //     std.debug.print("{}\n", .{data});
    // }

    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard optimization options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall. Here we do not
    // set a preferred release mode, allowing the user to decide how to optimize.
    const optimize = b.standardOptimizeOption(.{});

    const libbanana = b.addLibrary(.{
        .name = "banana_zig",
        .linkage = .dynamic,
        // In this case the main source file is merely a path, however, in more
        // complicated build scripts, this could be a generated file.
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/root.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });
    // libbanana.linkLibC();

    // This declares intent for the library to be installed into the standard
    // location when the user invokes the "install" step (the default step when
    // running `zig build`).
    b.getInstallStep().dependOn(&b.addInstallArtifact(libbanana, .{
        .dest_dir = .{
            .override = .{ .custom = "../../lua/banana/" },
        },
    }).step);
    b.installArtifact(libbanana);

    const exe = b.addExecutable(.{
        .name = "zig",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });
    // exe.linkLibC();
    // const tracy = b.option([]const u8, "tracy", "Enable Tracy integration. Supply path to Tracy source");
    // exe.addIncludePath(std.Build.LazyPath{ .path = "src/nvim" });

    // This declares intent for the executable to be installed into the
    // standard location when the user invokes the "install" step (the default
    // step when running `zig build`).
    b.installArtifact(exe);

    // This is where the interesting part begins.
    // As you can see we are re-defining the same
    // executable but we're binding it to a
    // dedicated build step.
    const exe_check = b.addExecutable(.{
        .name = "foo",
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });

    const libbananaCheck = b.addLibrary(.{
        .linkage = .dynamic,
        .name = "banana",
        // In this case the main source file is merely a path, however, in more
        // complicated build scripts, this could be a generated file.
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/root.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });
    // Any other code to define dependencies would
    // probably be here.

    // These two lines you might want to copy
    // (make sure to rename 'exe_check')
    const check = b.step("check", "Check if foo compiles");
    check.dependOn(&exe_check.step);
    check.dependOn(&libbananaCheck.step);

    // This *creates* a Run step in the build graph, to be executed when another
    // step is evaluated that depends on it. The next line below will establish
    // such a dependency.
    const run_cmd = b.addRunArtifact(exe);

    // By making the run step depend on the install step, it will be run from the
    // installation directory rather than directly from within the cache directory.
    // This is not necessary, however, if the application depends on other installed
    // files, this ensures they will be present and in the expected location.
    run_cmd.step.dependOn(b.getInstallStep());

    // This allows the user to pass arguments to the application in the build
    // command itself, like this: `zig build run -- arg1 arg2 etc`
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    // This creates a build step. It will be visible in the `zig build --help` menu,
    // and can be selected like this: `zig build run`
    // This will evaluate the `run` step rather than the default, which is "install".
    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    // Creates a step for unit testing. This only builds the test executable
    // but does not run it.
    const lib_unit_tests = b.addTest(.{
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/root.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });

    const run_lib_unit_tests = b.addRunArtifact(lib_unit_tests);

    const exe_unit_tests = b.addTest(.{
        .root_module = b.createModule(.{
            .root_source_file = b.path("src/main.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });

    const run_exe_unit_tests = b.addRunArtifact(exe_unit_tests);

    // Similar to creating the run step earlier, this exposes a `test` step to
    // the `zig build --help` menu, providing a way for the user to request
    // running the unit tests.
    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_lib_unit_tests.step);
    test_step.dependOn(&run_exe_unit_tests.step);
}
